// 
// file:			bsd/stdlib.h
// created on:		2019 Jan 25
// doc on header:	https://www.apt-browse.org/browse/ubuntu/trusty/main/i386/libbsd-dev/0.6.0-2ubuntu1/file/usr/include/bsd/string.h 
// 
// Almost all functions from this livbrary is from standard lib
// 

#ifndef __wlac_bsd_stdlib_h__
#define __wlac_bsd_stdlib_h__


#include <first_includes/common_include_for_headers.h>
#ifdef LIBBSD_OVERLAY
#pragma include_alias( <stdlib.h>, <stdlib.h> )
#pragma include_alias( "stdlib.h", "stdlib.h" )
#include <stdlib.h>  // should be #include_next
#else    // #ifdef LIBBSD_OVERLAY 
#include <stdlib.h>
#endif   // #ifdef LIBBSD_OVERLAY
#include <stddef.h> 


__BEGIN_C_DECLS


WLAC_TMP_API void arc4random_buf(void *buf, size_t nbytes);
WLAC_TMP_API int asprintf(char **strp, const char *fmt, ...);


__END_C_DECLS

#endif  // #ifndef __wlac_bsd_stdlib_h__
