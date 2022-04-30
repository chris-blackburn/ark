# Ark

I want to experiment with p2p comms and NAT traversal. Specifically, I want to
see if I can create a virtual LAN between peers.

Of course, you can always use [tuntap](https://en.wikipedia.org/wiki/TUN/TAP) to
create a virtual LAN (these create virtual interfaces through which we can route
traffic that meets certain criteria e.g. subnet). However, I was inspired to
take a different approach in order to learn how tools like [Game
Ranger](https://www.gameranger.com/) might work.

I also always love experimenting with build systems and programs, so I intend
for this to be an exercise on that front as well (the goal is to make this
cross-platform, but I'm starting with Linux).

## Build

run `scripts/build.sh`
