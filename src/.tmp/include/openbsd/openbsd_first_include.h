//
// file:        openbsd_first_include.h
// created on:  2019 Jan 27
//
#ifndef OPENBSD_FIRST_INCLUDE_H
#define OPENBSD_FIRST_INCLUDE_H

#ifndef __BEGIN_C_DECLS
#ifdef __cplusplus
#define __BEGIN_C_DECLS extern "C"{
#define __END_C_DECLS   }
#else
#define __BEGIN_C_DECLS
#define __END_C_DECLS
#endif
#endif

#ifndef OPEN_BSD_MISSING_FUNC
#define OPEN_BSD_MISSING_FUNC
#endif

#endif // OPENBSD_FIRST_INCLUDE_H
