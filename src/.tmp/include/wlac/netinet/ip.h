// 
// file:			netinet/ip.h
// created on:		2019 Jan 22
// docs on header:	http://web.mit.edu/freebsd/head/sys/netinet/ip.h 

#ifndef __wlac_netinet_ip_h__
#define __wlac_netinet_ip_h__


#include <first_includes/common_include_for_headers.h>

/*
 * Definitions for DiffServ Codepoints as per RFC2474
 */
#define	IPTOS_DSCP_CS0		0x00
#define	IPTOS_DSCP_CS1		0x20
#define	IPTOS_DSCP_AF11		0x28
#define	IPTOS_DSCP_AF12		0x30
#define	IPTOS_DSCP_AF13		0x38
#define	IPTOS_DSCP_CS2		0x40
#define	IPTOS_DSCP_AF21		0x48
#define	IPTOS_DSCP_AF22		0x50
#define	IPTOS_DSCP_AF23		0x58
#define	IPTOS_DSCP_CS3		0x60
#define	IPTOS_DSCP_AF31		0x68
#define	IPTOS_DSCP_AF32		0x70
#define	IPTOS_DSCP_AF33		0x78
#define	IPTOS_DSCP_CS4		0x80
#define	IPTOS_DSCP_AF41		0x88
#define	IPTOS_DSCP_AF42		0x90
#define	IPTOS_DSCP_AF43		0x98
#define	IPTOS_DSCP_CS5		0xa0
#define	IPTOS_DSCP_EF		0xb8
#define	IPTOS_DSCP_CS6		0xc0
#define	IPTOS_DSCP_CS7		0xe0

__BEGIN_C_DECLS



__END_C_DECLS


#endif  // #ifndef __wlac_netinet_ip_h__
