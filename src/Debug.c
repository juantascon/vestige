#define DEBUG
#ifdef DEBUG

#include <stdio.h>
#include <stdarg.h>

static void err_info(const char *file, const char *func, const int line)
{
	fprintf(stderr,"[%s:%s(%d)] ",file, func, line);
	fflush(stderr);
}

static void err_msg(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	
	vfprintf(stderr, format, args);
	fprintf(stderr, "\n");
	fflush(stderr);
	
	va_end(args);
}

#define D(x) { err_info(__FILE__, __FUNCTION__, __LINE__); err_msg x; } 

#else
#define D(x) {}
#endif
