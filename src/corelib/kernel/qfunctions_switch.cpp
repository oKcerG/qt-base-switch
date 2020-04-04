#include "qglobal.h"

#ifdef Q_OS_SWITCH

#include "qplatformdefs.h"
#include "qfunctions_vxworks.h"


#ifdef __cplusplus
extern "C" {
#endif

uid_t geteuid(void)
{
    return 0;
}

gid_t getgid()
{
    return 0;
}

uid_t getuid(void)
{
    return 0;
}

int getpagesize()
{
    return sysconf(_SC_PAGESIZE);
}

int symlink(const char *, const char *)
{
    errno = EIO;
    return -1;
}

ssize_t readlink(const char *, char *, size_t)
{
    errno = EIO;
    return -1;
}


struct passwd *getpwuid(uid_t uid)
{
    static struct passwd pwbuf = { "root", 0, 0, 0, 0, 0, 0 };

    if (uid == 0) {
        return &pwbuf;
    } else {
        errno = ENOENT;
        return 0;
    }
}

struct group *getgrgid(gid_t gid)
{
    static struct group grbuf = { "root", 0, 0, 0 };

    if (gid == 0) {
        return &grbuf;
    } else {
        errno = ENOENT;
        return 0;
    }
}

int sigaction(int, const struct sigaction *, struct sigaction *)
{
    return 0;
}

long sysconf(int name)
{
  switch (name)
  {
  case _SC_PAGESIZE:
    return 8;
  case _SC_NPROCESSORS_ONLN:
    return 4;
  case _SC_SYMLOOP_MAX:
  
  default:
    return -1;
  }
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // Q_OS_VXWORKS
