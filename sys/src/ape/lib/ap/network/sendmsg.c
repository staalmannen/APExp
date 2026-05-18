#include <sys/socket.h>
#include <errno.h>

/*
 * Stub for sendmsg. Plan 9 networking does not natively support
 * the complex POSIX sendmsg/recvmsg interface based on msghdr.
 * This stub returns ENOSYS to indicate that it is not implemented.
 */

ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags)
{
    errno = ENOSYS;
    return -1;
}
