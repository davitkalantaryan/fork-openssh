// 
// file:			bsd/vis.h
// created on:		2019 Jan 22
// doc on header:	https://github.com/openbsd/src/blob/master/include/vis.h 
// 

#ifndef __wlac_bsd_vis_h__
#define __wlac_bsd_vis_h__


#include <first_includes/common_include_for_headers.h>

/*
 * to alter set of characters encoded (default is to encode all
 * non-graphic except space, tab, and newline).
 */
#define	VIS_SP		0x04	/* also encode space */
#define	VIS_TAB		0x08	/* also encode tab */
#define	VIS_NL		0x10	/* also encode newline */
#define	VIS_WHITE	(VIS_SP | VIS_TAB | VIS_NL)
#define	VIS_SAFE	0x20	/* only encode "unsafe" characters */
#define	VIS_DQ		0x200	/* backslash-escape double quotes */
#define	VIS_ALL		0x400	/* encode all characters */


__BEGIN_C_DECLS

WLAC_TMP_API char * vis(char *dst, int c, int flag, int nextc);		// lib: (libbsd, -lbsd)

__END_C_DECLS

#endif  // #ifndef __wlac_bsd_vis_h__
