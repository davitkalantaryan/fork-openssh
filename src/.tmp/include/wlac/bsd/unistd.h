// 
// file:			bsd/unistd.h
// created on:		2019 Jan 25
// doc on header:	https://www.apt-browse.org/browse/ubuntu/trusty/main/i386/libbsd-dev/0.6.0-2ubuntu1/file/usr/include/bsd/string.h 
// 
// Almost all functions from this livbrary is from standard lib
// 

#ifndef __wlac_bsd_unistd_h__
#define __wlac_bsd_unistd_h__


#include <first_includes/common_include_for_headers.h>
#ifdef LIBBSD_OVERLAY
#pragma include_alias( <unistd.h>, <unistd.h> )
#pragma include_alias( "unistd.h", "unistd.h" )
#include <unistd.h>  // should be #include_next
#else   // #ifdef LIBBSD_OVERLAY
#include <unistd.h>
#endif  // #ifdef LIBBSD_OVERLAY


__BEGIN_C_DECLS

// 
// function pledge is not in bsd/unistd.h should be considered, whether keep it here
// 
WLAC_TMP_API int pledge(const char *promises, const char *execpromises); // https://man.openbsd.org/pledge.2

__END_C_DECLS

#endif  // #ifndef __wlac_bsd_unistd_h__
