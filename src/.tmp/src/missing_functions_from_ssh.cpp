

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>  
#include <stdarg.h>

void arc4random_buf(void *a_buf, size_t a_nbytes)
{
	int nRand = rand();
	uint64_t unValue = (uint64_t)nRand;
	size_t unCopy = a_nbytes<8 ? a_nbytes:8;
	memcpy(a_buf, &unValue, unCopy);
}


size_t strlcpy(char *a_dst, const char *a_src, size_t a_size)
{
	strncpy(a_dst, a_src, a_size);
	return strlen(a_src);
}

size_t strlcat(char *a_dst, const char *a_src, size_t a_size)
{
	size_t unReturn = strlen(a_dst) + strlen(a_src);
	strncat(a_dst, a_src, a_size);
	return unReturn;
}


int asprintf(char **a_strp, const char *a_fmt, ...)
{
	int nReturn;
	char vcBuffer[4096];
	va_list argsList;

	va_start(argsList, a_fmt);
	nReturn = vsnprintf(vcBuffer, 4095, a_fmt, argsList);
	va_end(argsList);

	*a_strp=strdup(vcBuffer);
	return nReturn;
}


#ifdef __cplusplus
}
#endif
