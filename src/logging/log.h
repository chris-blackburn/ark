#ifndef __LOGGING_H_
#define __LOGGING_H_

#include <stdio.h>

#define __LOG_COLOR_RED     "\033[0;31m"
#define __LOG_COLOR_GREEN   "\033[0;32m"
#define __LOG_COLOR_YELLOW  "\033[0;33m"
#define __LOG_COLOR_WHITE   "\033[0;37m"
#define __LOG_COLOR_RESET   "\033[0;0m"

#ifndef NDEBUG
#define __ARK_LOG(stream, color, lvl, fmt, ...) \
    fprintf(stream, color "[%s] (%s:%d) " __LOG_COLOR_RESET fmt "\n", lvl, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define __ARK_LOG(...)
#endif

#define LOG_INFO(fmt, ...)  __ARK_LOG(stderr, __LOG_COLOR_GREEN,     "INF", fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...) __ARK_LOG(stderr, __LOG_COLOR_WHITE,     "DBG", fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)  __ARK_LOG(stderr, __LOG_COLOR_YELLOW,    "WRN", fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) __ARK_LOG(stderr, __LOG_COLOR_RED,       "ERR", fmt, ##__VA_ARGS__)

#endif /* __LOGGING_H_ */
