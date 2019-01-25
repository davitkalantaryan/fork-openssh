// 
// file:		wlac_missing.cpp
// created on:	2019 Jan 22
// 


__BEGIN_C_DECLS


#ifndef CINTERFACE
#define CINTERFACE
#endif

#include "wlac_missing.h"
#include <Windows.h>
#include <stdint.h>
#include <glob.h>
#include <direct.h>
#include <stdlib.h>
#include <stdio.h>
//#include_next <stdio.h>

// 
// https://www.freebsd.org/cgi/man.cgi?query=closefrom&sektion=2&manpath=freebsd-release-ports
// To implement this function all handles of the process should be tried (to be done later)
// 
WLAC_TMP_API void closefrom(int lowfd)
{
	// 
}


// 
// https://www.freebsd.org/cgi/man.cgi?query=setproctitle&sektion=3 
// 
WLAC_TMP_API void setproctitle(const	char *fmt, ...)
{
}


// 
// https://linux.die.net/man/3/waitpid 
// https://docs.microsoft.com/en-us/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess 
// 
WLAC_TMP_API pid_t waitpid(pid_t a_nPid, int *stat_loc, int a_options)
{
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (a_nPid));

	if (hProcess){return -1;}

	WaitForSingleObject(hProcess, INFINITE);

	return FALSE;
}


// 
// https://man.openbsd.org/scan_scaled.3 
// 
WLAC_TMP_API int scan_scaled(char *number_w_scale, int64_t *result)
{
	return 0;
}


// 
// https://linux.die.net/man/3/glob 
// 
WLAC_TMP_API int glob(const char *pattern, int flags, int(*errfunc) (const char *epath, int eerrno), glob_t *pglob)
{
	return 0;
}


// 
// https://linux.die.net/man/3/glob 
// 
WLAC_TMP_API void globfree(glob_t *pglob)
{
}


// 
// https://linux.die.net/man/3/getline 
// 
WLAC_TMP_API ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	return 0;
}


// 
// https://linux.die.net/man/3/vis 
// libbsd
// 
WLAC_TMP_API char * vis(char *dst, int c, int flag, int nextc)
{
	return dst;
}


// 
// https://linux.die.net/man/3/mkdtemp
// https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/mktemp-wmktemp?view=vs-2017
//#define mkdtemp	_mktemp    // should be in stdlib.h
//
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning (disable:4996)
#endif
WLAC_TMP_API char *mkdtemp(char *a_templateName)
{
	_mkdir(_mktemp(a_templateName));
	return a_templateName;
}
#ifdef _MSC_VER
#pragma warning(pop)
#endif


// 
// doc:		https://www.freebsd.org/cgi/man.cgi?query=strlcpy&sektion=3 
// header:	bsd/string.h
//
WLAC_TMP_API size_t strlcpy(char *a_dst, const char *a_src, size_t a_size)
{
	strncpy(a_dst, a_src, a_size);
	return strlen(a_src);
}


// 
// doc:		https://www.freebsd.org/cgi/man.cgi?query=strlcpy&sektion=3 
// header:	bsd/string.h
//
WLAC_TMP_API size_t strlcat(char *a_dst, const char *a_src, size_t a_size)
{
	size_t unReturn = strlen(a_dst) + strlen(a_src);
	strncat(a_dst, a_src, a_size);
	return unReturn;
}


// 
// doc:		https://www.freebsd.org/cgi/man.cgi?query=arc4random_buf&sektion=3&manpath=freebsd-release-ports  
// header:	bsd/stdio.h
//
WLAC_TMP_API void arc4random_buf(void *a_buf, size_t a_nbytes)
{
	int nRand = rand();
	uint64_t unValue = (uint64_t)nRand;
	size_t unCopy = a_nbytes < 8 ? a_nbytes : 8;
	memcpy(a_buf, &unValue, unCopy);
}


// 
// doc:		https://www.freebsd.org/cgi/man.cgi?query=arc4random_buf&sektion=3&manpath=freebsd-release-ports  
// header:	bsd/stdio.h
//
WLAC_TMP_API int asprintf(char **a_strp, const char *a_fmt, ...)
{
	int nReturn;
	char vcBuffer[4096];
	va_list argsList;

	va_start(argsList, a_fmt);
	nReturn = vsnprintf(vcBuffer, 4095, a_fmt, argsList);
	va_end(argsList);

	*a_strp = strdup(vcBuffer);
	return nReturn;
}


// 
// doc:		https://man.openbsd.org/pledge.2   
// header:	bsd/unistd.h
// 
WLAC_TMP_API int pledge(const char *promises, const char *execpromises)
{
	return 0;
}

__END_C_DECLS
