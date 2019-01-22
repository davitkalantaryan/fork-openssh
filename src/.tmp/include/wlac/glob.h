// 
// file:			glob.h
// created on:		2019 Jan 22
// doc on header:	http://pubs.opengroup.org/onlinepubs/009604499/basedefs/glob.h.html 
// 

#ifndef __wlac_glob_h__
#define __wlac_glob_h__

#include <first_includes/common_include_for_headers.h>
#include <stddef.h>

/*

https://linux.die.net/man/3/glob 

GLOB_ERR
  Return upon a read error 
  (because a directory does not have read permission, for example). 
  By default, glob() attempts carry on despite errors, reading all of the directories that it can.
GLOB_MARK
  Append a slash to each path which corresponds to a directory.
GLOB_NOSORT
  Don't sort the returned pathnames. 
  The only reason to do this is to save processing time. By default, the returned pathnames are sorted.
GLOB_DOOFFS
  Reserve pglob->gl_offs slots at the beginning of the list of strings in pglob->pathv. 
  The reserved slots contain NULL pointers.
GLOB_NOCHECK
  If no pattern matches, return the original pattern. By default, glob() returns 
GLOB_NOMATCH 
  if there are no matches.
GLOB_APPEND
  Append the results of this call to the vector of results returned by a previous call to glob(). 
  Do not set this flag on the first invocation of glob().
GLOB_NOESCAPE
  Don't allow backslash ('\') to be used as an escape character. Normally, 
  a backslash can be used to quote the following character, providing a mechanism to turn off the special meaning metacharacters.
  flags may also include any of the following, which are GNU extensions and not defined by POSIX.2:
GLOB_PERIOD
  Allow a leading period to be matched by metacharacters. By default, metacharacters can't match a leading period.
GLOB_ALTDIRFUNC
  Use alternative functions pglob->gl_closedir, pglob->gl_readdir, pglob->gl_opendir, pglob->gl_lstat, 
  and pglob->gl_stat for file system access instead of the normal library functions.
GLOB_BRACE
  Expand csh(1) style brace expressions of the form {a,b}. Brace expressions can be nested. 
  Thus, for example, specifying the pattern "{foo/{,cat,dog},bar}" would return the same results as four separate glob() calls using the strings: 
  "foo/", "foo/cat", "foo/dog", and "bar".
GLOB_NOMAGIC
  If the pattern contains no metacharacters then it should be returned as the sole matching word, even if there is no file with that name.
GLOB_TILDE
  Carry out tilde expansion. If a tilde ('~') is the only character in the pattern, or an initial tilde is followed immediately by a slash ('/'), 
  then the home directory of the caller is substituted for the tilde. If an initial tilde is followed by a username (e.g., "~andrea/bin"), 
  then the tilde and username are substituted by the home directory of that user. If the username is invalid, 
  or the home directory cannot be determined, then no substitution is performed.
GLOB_TILDE_CHECK
  This provides behavior similar to that of GLOB_TILDE. The difference is that if the username is invalid, 
  or the home directory cannot be determined, then instead of using the pattern itself as the name, 
  glob() returns GLOB_NOMATCH to indicate an error.
GLOB_ONLYDIR
  This is a hint to glob() that the caller is interested only in directories that match the pattern. 
  If the implementation can easily determine file-type information, then nondirectory files are not returned to the caller. 
  However, the caller must still check that returned files are directories. 
  (The purpose of this flag is merely to optimize performance when the caller is interested only in directories.)

 */

#define GLOB_ERR			0x1
#define GLOB_MARK			0x2
#define GLOB_NOSORT			0x4
#define GLOB_DOOFFS			0x8

#define GLOB_APPEND			0x10
#define GLOB_NOESCAPE		0x20
#define GLOB_PERIOD			0x40
#define GLOB_ALTDIRFUNC		0x80

#define GLOB_BRACE			0x100
#define GLOB_NOMAGIC		0x200
#define GLOB_TILDE			0x400
#define GLOB_TILDE_CHECK	0x800

#define GLOB_ONLYDIR		0x1000
#define GLOB_NOMATCH		0x2000

__BEGIN_C_DECLS

typedef struct {
	size_t   gl_pathc;    /* Count of paths matched so far  */
	char   **gl_pathv;    /* List of matched pathnames.  */
	size_t   gl_offs;     /* Slots to reserve in gl_pathv.  */
} glob_t;


// https://linux.die.net/man/3/glob

WLAC_TMP_API int glob(const char *pattern, int flags,int(*errfunc) (const char *epath, int eerrno),glob_t *pglob);	// lib: ???
WLAC_TMP_API void globfree(glob_t *pglob);																			// lib: ???


__END_C_DECLS


#endif  // #ifndef __wlac_glob_h__
