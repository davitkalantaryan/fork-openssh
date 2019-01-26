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
#include <io.h>
#include <strings.h>

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

// https://linux.die.net/man/3/popen
// https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/popen-wpopen?view=vs-2017 
// https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/pclose?view=vs-2017 
#define popen			_popen		// should be dne in stdio.h
#define pclose			_pclose		// should be dne in stdio.h

// https://www.freebsd.org/cgi/man.cgi?query=explicit_bzero&sektion=3&manpath=freebsd-release-ports
#define explicit_bzero	bzero

// 
// header:	termios.h
// doc:		http://man7.org/linux/man-pages/man4/tty_ioctl.4.html 
// 
#define TIOCGWINSZ	0x5413


__BEGIN_C_DECLS


WLAC_TMP_API void closefrom(int lowfd);									// header: unistd.h; lib: Standard C library
WLAC_TMP_API void setproctitle(const	char *fmt, ...);				// header: sys/types.h,unistd.h; lib: ???
WLAC_TMP_API pid_t waitpid(pid_t pid, int *stat_loc, int options);		// header: sys/wait.h; lib: ???
WLAC_TMP_API ssize_t getline(char **lineptr, size_t *n, FILE *stream);	// header: stdio.h; lib: ??? 
WLAC_TMP_API char *mkdtemp(char *templateName);							// header: stdlib.h; lib: Standard C library 
//WLAC_TMP_API void bzero(void	*b, size_t len);						// header: strings.h; lib: Standard C library 


__END_C_DECLS


#endif  // #ifndef __wlac_missing_h__
