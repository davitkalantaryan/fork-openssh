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

#ifndef CINTERFACE
#define CINTERFACE
#endif

#include <first_includes/common_include_for_headers.h>
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

//#define arc4random_buf()
void arc4random_buf(void *buf, size_t nbytes);

// #define strlcpy strncpy
size_t strlcpy(char *dst, const char *src, size_t size);
size_t strlcat(char *dst, const char *src, size_t size);

int asprintf(char **strp, const char *fmt, ...);


#ifdef __cplusplus
}
#endif



#endif   // #ifndef __openssh_first_include_h__
