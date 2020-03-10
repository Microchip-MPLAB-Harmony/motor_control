#ifndef TOOLCHAIN_SPECIFICS_H
#define TOOLCHAIN_SPECIFICS_H

#ifdef __ICCARM__

#define ssize_t long

#else
#include <sys/types.h>
#endif


#endif //TOOLCHAIN_SPECIFICS_H
