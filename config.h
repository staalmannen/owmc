
/* custom config.h for Open Watcom */
#ifndef __WINE_CONFIG_H

#define __WINE_CONFIG_H 1
#define PACKAGE_VERSION "0.1"

/* headers */
#undef HAVE_DLFCN_H
#define HAVE_DIRECT_H 1
#define HAVE_IO_H 1
#define HAVE_PROCESS_H 1
#define HAVE_UNISTD_H 1
#undef HAVE_GETTEXT_PO_H
/* #define HAVE_SYS_TIME_H 1*/

/* functions */
#define HAVE_ONE_ARG_MKDIR 1
#define HAVE_CHSIZE 1
#define HAVE__POPEN 1
#define HAVE__PCLOSE 1
#define HAVE_STRDUP 1
#define HAVE_SNPRINTF 1
#define HAVE_VSNPRINTF 1
#define HAVE_STRTOLL 1
#define HAVE_STRTOULL 1
#undef HAVE_GETOPT_LONG
#define HAVE_STRNCASECMP 1
#define HAVE_STRERROR 1
#define HAVE_USLEEP 1
#define HAVE_ISINF 1
#define HAVE_ISNAN 1

/*hacks?*/
#define WC_ERR_INVALID_CHARS 0x00000008L /*MB_ERR_INVALID_CHARS*/
#define WINVER 0x0601

#endif /* __WINE_CONFIG_H */


