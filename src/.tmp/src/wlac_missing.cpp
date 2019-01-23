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

__END_C_DECLS
