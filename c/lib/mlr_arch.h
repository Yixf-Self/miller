#ifndef MLR_ARCH_H
#define MLR_ARCH_H

#include <stdio.h>

// ----------------------------------------------------------------
// Miller is single-threaded and the file-locking in getc is simply an unneeded
// performance hit, so we intentionally call getc_unlocked().  But for MSYS2
// (Windows port), there exists no such.
#ifdef MLR_ON_MSYS2
#define mlr_arch_getc(stream) getc(stream)
#else
#define mlr_arch_getc(stream) getc_unlocked(stream)
#endif

// ----------------------------------------------------------------
#ifdef MLR_ON_MSYS2
#define MLR_ARCH_MMAP_ENABLED 0
#else
#define MLR_ARCH_MMAP_ENABLED 1
#include <sys/mman.h>
#endif

// ----------------------------------------------------------------
int mlr_arch_setenv(const char *name, const char *value);
int mlr_arch_unsetenv(const char *name);

// ----------------------------------------------------------------
char* mlr_arch_strsep(char **pstring, const char *delim);

// ----------------------------------------------------------------
ssize_t mlr_arch_getdelim(char** restrict pline, size_t* restrict plinecap, int delimiter, FILE* restrict stream);

#endif // MLR_ARCH_H