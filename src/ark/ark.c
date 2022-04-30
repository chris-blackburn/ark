#include <ark.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "types.h"
#include "logging/log.h"

int ark_run(void)
{
    int listenfd;
    int peerfd;
    int optval;
    struct sockaddr_in addr = { 0 };
    struct sockaddr_in peer_addr = { 0 };
    socklen_t addrlen;
    unsigned char buf[64];
    ssize_t nrread;
    ssize_t nrwrote;
    int rc;

    LOG_INFO("Starting ark");

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        LOG_ERROR("Failed to create listen socket (errno=%d)", errno);
        return -1;
    }

    optval = 1;
    rc = setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval,
            sizeof(optval));
    if (rc < 0) {
        LOG_ERROR("Failed to set reuseaddr on listen socket (errno=%d)", errno);
        return -1;
    }

    /* Setup the addr */
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(8080);

    rc = bind(listenfd, (struct sockaddr*)&addr, sizeof(addr));
    if (rc < 0) {
        LOG_ERROR("Failed to bind listener (errno=%d)", errno);
        return -1;
    }

    LOG_INFO("Listening");

    rc = listen(listenfd, 1);
    if (rc < 0) {
        LOG_ERROR("Failed to listen (errno=%d)", errno);
        return -1;
    }

    while (1) {
        addrlen = sizeof(peer_addr);
        peerfd = accept(listenfd, (struct sockaddr*)&peer_addr, &addrlen);
        if (rc < 0) {
            LOG_ERROR("Failed to accept (errno=%d)", errno);
            return -1;
        }

        LOG_INFO("New connection");

        memset(buf, 0, sizeof(buf));
        nrread = recv(peerfd, buf, sizeof(buf), 0);
        if (nrread < 0) {
            LOG_ERROR("Failed to recv (errno=%d)", errno);
            return -1;
        }

        LOG_INFO("(%ld bytes) '%s'", nrread, buf);

        nrwrote = send(peerfd, buf, nrread, 0);
        if (nrwrote < 0) {
            LOG_ERROR("Failed to send (errno=%d)", errno);
            return -1;
        }

        close(peerfd);
    }

    close(listenfd);

    return 0;
}
