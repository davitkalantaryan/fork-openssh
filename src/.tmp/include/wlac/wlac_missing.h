// 
// file:		wlac_missing.h
// created on:	201119 Jan 22
// 
//    The purpose of this file is to declare missing functions and variables for WLAC
//    with each declaration the header and library should be mentioned
//

#ifndef __wlac_missing_h__
#define __wlac_missing_h__

#include <first_includes/common_include_for_headers.h>
#include <stdlib.h>
#include <Windows.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/uio.h>

#ifndef WLAC_TMP_API
#define WLAC_TMP_API
#endif

#ifndef _PATH_BSHELL
#define _PATH_BSHELL	"bash.exe"
#endif

#if !defined(setenv) && !defined(setenv_defined)
#define setenv( _name, _value, _overwrite)		( SetEnvironmentVariableA((_name),(_value)) ? 0 : -1  )
#define setenv_defined
#endif 

__BEGIN_C_DECLS


WLAC_TMP_API void closefrom(int lowfd);									// header: unistd.h; lib: Standard C library
WLAC_TMP_API void setproctitle(const	char *fmt, ...);				// header: sys/types.h,unistd.h; lib: ???
WLAC_TMP_API pid_t waitpid(pid_t pid, int *stat_loc, int options);		// header: sys/wait.h; lib: ???
WLAC_TMP_API ssize_t getline(char **lineptr, size_t *n, FILE *stream);	// header: stdio.h; lib: ??? 


__END_C_DECLS


#endif  // #ifndef __wlac_missing_h__
