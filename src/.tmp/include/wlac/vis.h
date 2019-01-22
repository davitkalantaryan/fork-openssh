// 
// file:			vis.h
// created on:		2019 Jan 22
// doc on header:	https://github.com/openbsd/src/blob/master/include/vis.h 
// 

#ifndef __wlac_vis_h__
#define __wlac_vis_h__


#include <first_includes/common_include_for_headers.h>
#include <bsd/vis.h>


__BEGIN_C_DECLS

WLAC_TMP_API char * vis(char *dst, int c, int flag, int nextc);		// lib: (libbsd, -lbsd)

__END_C_DECLS

#endif  // #ifndef __wlac_vis_h__
