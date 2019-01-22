// 
// file:			util.h
// created on:		2019 Jan 22
// doc on header:	???
// 

#ifndef __wlac_util_h__
#define __wlac_util_h__


#include <first_includes/common_include_for_headers.h>
#include <stdint.h>

__BEGIN_C_DECLS

WLAC_TMP_API int scan_scaled(char *number_w_scale, int64_t *result);  // header: util.h; lib: ??? (https://man.openbsd.org/scan_scaled.3)

__END_C_DECLS

#endif  // #ifndef __wlac_util_h__
