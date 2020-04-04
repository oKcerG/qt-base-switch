#ifndef QFUNCTIONS_SWITCH_H
#define QFUNCTIONS_SWITCH_H

#include <QtCore/qglobal.h>

#ifdef Q_OS_SWITCH



#ifdef __cplusplus
extern "C" {
#endif

uid_t geteuid(void);

gid_t getgid();

uid_t getuid(void);

int getpagesize();

int symlink(const char *, const char *);

ssize_t readlink(const char *, char *, size_t);

struct passwd *getpwuid(uid_t uid);

struct group *getgrgid(gid_t gid);

int sigaction(int, const struct sigaction *, struct sigaction *);

long sysconf(int name);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // Q_OS_SWITCH
#endif // QFUNCTIONS_SWITCH_H
