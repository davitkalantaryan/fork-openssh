// 
// file:			openssh_first_include.h
// created on:		2019 Jan 22
// 

#ifndef __openssh_first_include_h__
#define __openssh_first_include_h__

//#define _USE_NEW_STRUCTS


#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <openbsd/openbsd_first_include.h>

#define IOV_MAX 1024

// 
// header:	stdlib.h   (from openbsd)
// doc:		https://man.openbsd.org/malloc.3
// 
OPEN_BSD_MISSING_FUNC void * recallocarray(void *ptr, size_t oldnmemb, size_t newnmemb, size_t size);

// https://www.freebsd.org/cgi/man.cgi?query=explicit_bzero&sektion=3&manpath=freebsd-release-ports
#define explicit_bzero	bzero

#ifdef _WIN32

#ifndef CINTERFACE
#define CINTERFACE
#endif

#include <first_includes/common_include_for_headers.h>
//#include <bsd/first_wlac_bsd_include.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <stdint.h>
//#include <redesigned/stdio.h>

#pragma warning(disable:4996)
#pragma warning(disable:4244)
#pragma warning(disable:4267)
#pragma warning(disable:4133)
#pragma warning(disable:4018)


#ifndef __attribute__
#define __attribute__(...)
#endif

#define SHUT_RDWR		SD_BOTH
#define S_IFSOCK		1    // should be fixed
#define S_IFIFO			_S_IFIFO
#define MAXPATHLEN		MAX_PATH

#ifndef _PATH_DEVNULL
#define _PATH_DEVNULL  "/dev/null"
#endif

#ifndef __u_int64_t_defined
typedef uint64_t u_int64_t;
#define __u_int64_t_defined
#endif

#ifndef __u_int16_t_defined
typedef uint16_t u_int16_t;
#define __u_int16_t_defined
#endif

#ifndef __u_int8_t_defined
typedef uint8_t u_int8_t;
#define __u_int8_t_defined
#endif

#include <string.h>
#include <wlac_missing.h>
#include <stdlib.h>
#include <sys/wait.h>

#ifdef WITH_OPENSSL

#include <openssl/evp.h>
#include <openssl/ossl_typ.h>
#include <evp_locl.h>


#include <openssl/rsa.h>
#include <openssl/dsa.h>

typedef int CRYPTO_REF_COUNT;

struct rsa_st
{
	/* The first parameter is used to pickup errors where
	 * this is passed instead of aEVP_PKEY, it is set to 0 */
	int pad;
	long version;
	const RSA_METHOD *meth;
	/* functional reference if 'meth' is ENGINE-provided */
	ENGINE *engine;
	BIGNUM *n;
	BIGNUM *e;
	BIGNUM *d;
	BIGNUM *p;
	BIGNUM *q;
	BIGNUM *dmp1;
	BIGNUM *dmq1;
	BIGNUM *iqmp;
	/* be careful using this if the RSA structure is shared */
	CRYPTO_EX_DATA ex_data;
	int references;
	int flags;

	/* Used to cache montgomery values */
	BN_MONT_CTX *_method_mod_n;
	BN_MONT_CTX *_method_mod_p;
	BN_MONT_CTX *_method_mod_q;

	/* all BIGNUM values are actually in the following data, if it is not
	 * NULL */
	char *bignum_data;
	BN_BLINDING *blinding;
};

struct dsa_st {
	/*
	 * This first variable is used to pick up errors where a DSA is passed
	 * instead of of a EVP_PKEY
	 */
	int pad;
	int32_t version;
	BIGNUM *p;
	BIGNUM *q;                  /* == 20 */
	BIGNUM *g;
	BIGNUM *pub_key;            /* y public key */
	BIGNUM *priv_key;           /* x private key */
	int flags;
	/* Normally used to cache montgomery values */
	BN_MONT_CTX *method_mont_p;
	CRYPTO_REF_COUNT references;
	CRYPTO_EX_DATA ex_data;
	const DSA_METHOD *meth;
	/* functional reference if 'meth' is ENGINE-provided */
	ENGINE *engine;
	CRYPTO_RWLOCK *lock;
};

struct evp_pkey_st {
	int type;
	int save_type;
	int references;
	const EVP_PKEY_ASN1_METHOD *ameth;
	ENGINE *engine;
	union {
		void *ptr;
# ifndef OPENSSL_NO_RSA
		struct rsa_st *rsa;     /* RSA */
# endif
# ifndef OPENSSL_NO_DSA
		struct dsa_st *dsa;     /* DSA */
# endif
# ifndef OPENSSL_NO_DH
		struct dh_st *dh;       /* DH */
# endif
# ifndef OPENSSL_NO_EC
		struct ec_key_st *ec;   /* ECC */
# endif
	} pkey;
	int save_parameters;
	STACK_OF(X509_ATTRIBUTE) *attributes; /* [ 0 ] */
	CRYPTO_RWLOCK *lock;
} /* EVP_PKEY */;

#endif  // #ifdef WITH_OPENSSL


#else   // #ifdef _WIN32

//#error my error
#define __USE_GNU
#include <netdb.h>
#ifndef EAI_NODATA
#  define EAI_NODATA	  -5	/* No address associated with NAME.  */
#endif

#include <netinet/in.h>
#include <netinet/ip.h>

#include <sys/queue.h>
#if !defined(TAILQ_FOREACH_SAFE) && !defined(TAILQ_FOREACH_SAFE_defined)
#define TAILQ_FOREACH_SAFE(_id, _files, _next, _tmp)    TAILQ_FOREACH(_id, _files, _next)
#endif

#ifndef VIS_ALL
#define VIS_ALL 0xffffffff
#endif

//
// doc: https://man.openbsd.org/setsockopt.2
//
#ifndef SO_RTABLE
#define SO_RTABLE   1
#endif

#include <netinet/ip.h>

#ifndef IPTOS_DSCP_CS0
#define	IPTOS_DSCP_CS0			IPTOS_CLASS_CS0
#define	IPTOS_DSCP_CS1			IPTOS_CLASS_CS1
#define	IPTOS_DSCP_CS2			IPTOS_CLASS_CS2
#define	IPTOS_DSCP_CS3			IPTOS_CLASS_CS3
#define	IPTOS_DSCP_CS4			IPTOS_CLASS_CS4
#define	IPTOS_DSCP_CS5			IPTOS_CLASS_CS5
#define	IPTOS_DSCP_CS6			IPTOS_CLASS_CS6
#define	IPTOS_DSCP_CS7			IPTOS_CLASS_CS7
#endif

#ifndef SYSLOG_DATA_INIT
#define SYSLOG_DATA_INIT {0}
#endif

#ifdef SYSLOG_NAMES
#undef SYSLOG_NAMES // this sould be done only in one source file
#endif
#include <sys/syslog.h>
//#include >

// https://github.com/openbsd/src/blob/master/sys/sys/syslog.h
struct syslog_data {
    int	log_stat;
    const char 	*log_tag;
    int 	log_fac;
    int 	log_mask;
};


//#include <lwres/netdb.h>
#include <X11/Xpoll.h>  // howmany is here

#ifndef WITH_OPENSSL
typedef int EVP_CIPHER_CTX;
#endif

// https://www.daemon-systems.org/man/__predict_false.3.html
#include <sys/cdefs.h>
#ifndef __predict_false
#define __predict_false(_expr)  (_expr)
#endif

//#define explicit_bzero	bzero

int   scan_scaled(char *number_w_scale, long long *result);		// header: util.h; lib: ??? (https://man.openbsd.org/scan_scaled.3)
//void  explicit_bzero(void *b, size_t len);						// header: strings.h; lib: ??? (https://man.openbsd.org/scan_scaled.3)
int   pledge(const char *promises, const char *execpromises);	// header: unistd.h; lib: Standars C (https://man.openbsd.org/pledge.2 )
void  freezero(void *ptr, size_t size);							// header: stdlib.h; lib: ??? (https://man.openbsd.org/malloc.3 )
int   timingsafe_bcmp(const void *b1, const void *b2, size_t len);// header: string.h; lib: ??? (https://man.openbsd.org/timingsafe_bcmp.3 )
//int   asprintf(char **strp, const char *fmt, ...);// header: stdio.h, lib: ??? (http://man7.org/linux/man-pages/man3/asprintf.3.html)
int   syslog_r(int Priority,struct syslog_data* SysLogData, const char* Format,...); // header: syslog.h, lib: Standard C (https://www.ibm.com/support/knowledgecenter/en/ssw_aix_71/com.ibm.aix.basetrf2/syslog_r.htm)
int   openlog_r (const char* ID, int LogOption, int Facility, struct syslog_data* SysLogData);// header: syslog.h, lib: Standard C (https://www.ibm.com/support/knowledgecenter/en/ssw_aix_71/com.ibm.aix.basetrf2/syslog_r.htm)
void  closelog_r(struct syslog_data* SysLogData);// header: syslog.h, lib: Standard C (https://www.ibm.com/support/knowledgecenter/en/ssw_aix_71/com.ibm.aix.basetrf2/syslog_r.htm)
void* reallocarray(void *ptr, size_t nmemb, size_t size); // header: bsd/stdlib.h, lib: Standard C (https://www.freebsd.org/cgi/man.cgi?query=reallocarray&sektion=3&manpath=freebsd-release-ports)
int   bcrypt_pbkdf(const char *pass, size_t pass_len, const uint8_t *salt, size_t salt_len, uint8_t *key, size_t key_len, unsigned int rounds); // header: util.h, lib: ??? (https://man.openbsd.org/bcrypt_pbkdf.3)

#endif  // #ifdef _WIN32


#ifdef __cplusplus
}
#endif



#endif   // #ifndef __openssh_first_include_h__
