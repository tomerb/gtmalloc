/*
** 2001 September 16
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
******************************************************************************
**
** This header file (together with is companion C source-code file
** "os.c") attempt to abstract the underlying operating system so that
** the SQLite library will work on both POSIX and windows systems.
**
** This header file is #include-ed by sqliteInt.h and thus ends up
** being included by every source file.
*/
#ifndef _SQLITE_OS_H_
#define _SQLITE_OS_H_

/*
** Figure out if we are dealing with Unix, Windows, or some other
** operating system.  After the following block of preprocess macros,
** all of SQLITE_OS_UNIX, SQLITE_OS_WIN, and SQLITE_OS_OTHER 
** will defined to either 1 or 0.  One of the four will be 1.  The other 
** three will be 0.
*/
#if defined(SQLITE_OS_OTHER)
# if SQLITE_OS_OTHER==1
#   undef SQLITE_OS_UNIX
#   define SQLITE_OS_UNIX 0
#   undef SQLITE_OS_WIN
#   define SQLITE_OS_WIN 0
# else
#   undef SQLITE_OS_OTHER
# endif
#endif
#if !defined(SQLITE_OS_UNIX) && !defined(SQLITE_OS_OTHER)
# define SQLITE_OS_OTHER 0
# ifndef SQLITE_OS_WIN
#   if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#     define SQLITE_OS_WIN 1
#     define SQLITE_OS_UNIX 0
#   else
#     define SQLITE_OS_WIN 0
#     define SQLITE_OS_UNIX 1
#  endif
# else
#  define SQLITE_OS_UNIX 0
# endif
#else
# ifndef SQLITE_OS_WIN
#  define SQLITE_OS_WIN 0
# endif
#endif

#if SQLITE_OS_WIN
# include <windows.h>
#endif



#endif /* _SQLITE_OS_H_ */
