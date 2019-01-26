// 
// file:			bsd/string.h
// created on:		2019 Jan 25
// doc on header:	https://www.apt-browse.org/browse/ubuntu/trusty/main/i386/libbsd-dev/0.6.0-2ubuntu1/file/usr/include/bsd/string.h 
// 
// Almost all functions from this livbrary is from standard lib
// 

#ifndef __wlac_bsd_string_h__
#define __wlac_bsd_string_h__


#include <first_includes/common_include_for_headers.h>
#ifdef LIBBSD_OVERLAY
#pragma include_alias( <string.h>, <string.h> )
#pragma include_alias( "string.h", "string.h" )
#include <string.h>  // should be #include_next
#else   // #ifdef LIBBSD_OVERLAY
#include <string.h>
#endif  // #ifdef LIBBSD_OVERLAY
#include <stddef.h>


__BEGIN_C_DECLS

// #define strlcpy strncpy
WLAC_TMP_API size_t strlcpy(char *dst, const char *src, size_t size);
WLAC_TMP_API size_t strlcat(char *dst, const char *src, size_t size);


__END_C_DECLS

#endif  // #ifndef __wlac_bsd_string_h__
