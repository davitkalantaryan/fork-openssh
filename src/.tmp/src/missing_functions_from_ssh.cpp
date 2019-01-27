
#include <openssh_first_include.h>
#include <openbsd/openbsd_first_include.h>

__BEGIN_C_DECLS

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>  
#include <stdarg.h>
#include <syslog.h>
	

// 
// https://man.openbsd.org/scan_scaled.3 
// 
OPEN_BSD_MISSING_FUNC int scan_scaled(char *a_number_w_scale, long long *a_result)
{
	char* pcTerm=NULL;
	double lfValue=strtod(a_number_w_scale, &pcTerm);

	if((pcTerm==a_number_w_scale)||(!pcTerm)){return -1;}

	switch(*(pcTerm+1)){
	case 'K': case 'k':  // Kilobyte
		*a_result = (long long)(1024. * lfValue);
		break;
	case 'M': case 'm':  // Megabyte
		*a_result = (long long)(1048576. * lfValue);
		break;
	case 'G': case 'g':  // Gigabyte
		*a_result = (long long)(1073741824. * lfValue);
		break;
	case 'T': case 't':  // Terabyte
		*a_result = (long long)(1099511627776. * lfValue);
		break;
	case 'P': case 'p':  // Petabyte
		*a_result = (long long)(1125899906842624. * lfValue);
		break;
	case 'E': case 'e':  // Exabyte
		*a_result = (long long)(1152921504606846976. * lfValue);
		break;
	default:  // Byte
		*a_result = (long long)lfValue;
		break;
	}

	return 0;
}


// 
// doc:		https://man.openbsd.org/pledge.2   
// header:	bsd/unistd.h
// 
OPEN_BSD_MISSING_FUNC int pledge(const char *promises, const char *execpromises)
{
	return 0;
}


//
// header: stdlib.h  (from freeBsd)
// lib: Standard C	Library	(libc, -lc)
// doc: https://www.freebsd.org/cgi/man.cgi?query=reallocarray&sektion=3&manpath=freebsd-release-ports
//
OPEN_BSD_MISSING_FUNC void * reallocarray(void *a_ptr, size_t a_newnmemb, size_t a_size)
{
    //size_t oldSize = a_oldnmemb * a_size;
    size_t newSize = a_newnmemb * a_size;
    char* pcReturn ;

    //if(newSize>oldSize)
    {
        pcReturn = (char*)realloc(a_ptr, newSize);
        //if (pcReturn) {memset(pcReturn+oldSize,0,(newSize-oldSize));}
    }
    //else {pcReturn=(char*)a_ptr;}
    return pcReturn;
}


OPEN_BSD_MISSING_FUNC void * recallocarray(void * a_ptr, size_t a_oldnmemb, size_t a_newnmemb, size_t a_size)
{
	size_t oldSize = a_oldnmemb * a_size;
	size_t newSize = a_newnmemb * a_size;
	char* pcReturn ;

	if(newSize>oldSize){
		pcReturn = (char*)realloc(a_ptr, newSize);
		if (pcReturn) {memset(pcReturn+oldSize,0,(newSize-oldSize));}
	}
	else {pcReturn=(char*)a_ptr;}
	return pcReturn;
}


//
// doc:		https://man.openbsd.org/malloc.3
// header:	stdlib.h   (openbsd)
//
OPEN_BSD_MISSING_FUNC void  freezero(void *a_ptr, size_t a_size)
{
    free(a_ptr);
}


//
// doc:		https://www.freebsd.org/cgi/man.cgi?query=timingsafe_memcmp&apropos=0&sektion=3&manpath=FreeBSD+11-current&format=html
// header:	string.h   (openbsd)
//
OPEN_BSD_MISSING_FUNC int timingsafe_bcmp(const void	*a_b1, const void	*a_b2, size_t a_len)
{
    int nReturn = memcmp(a_b1,a_b2,a_len);
    // something else to do ?
    return nReturn;
}


//
// header: ???
// doc: https://www.ibm.com/support/knowledgecenter/en/ssw_aix_71/com.ibm.aix.basetrf2/syslog_r.htm
//
int syslog_r(int a_priority,struct syslog_data* a_sysLogData, const char* a_format,...)
{
    va_list argList;

    syslog(a_priority,"%d;\"%s\";%d;%d -> ",a_sysLogData->log_stat,a_sysLogData->log_tag,a_sysLogData->log_fac,a_sysLogData->log_mask);

    va_start(argList,a_format);
    vsyslog(a_priority,a_format,argList);
    va_end(argList);
    return 0;
}


//
// header: ???
// doc: https://www.ibm.com/support/knowledgecenter/en/ssw_aix_71/com.ibm.aix.basetrf2/syslog_r.htm
//
int openlog_r (const char* a_ID, int a_logOption, int a_facility, struct syslog_data* a_sysLogData)
{
    openlog(a_ID,a_logOption,a_facility);
    syslog(LOG_INFO,"open: %d;\"%s\";%d;%d -> ",a_sysLogData->log_stat,a_sysLogData->log_tag,a_sysLogData->log_fac,a_sysLogData->log_mask);
    return 0;
}


//
// header: syslog.h, lib: Standard C
// doc: https://www.ibm.com/support/knowledgecenter/en/ssw_aix_71/com.ibm.aix.basetrf2/syslog_r.htm
//
void  closelog_r(struct syslog_data* a_sysLogData)
{
    closelog();
    syslog(LOG_INFO,"close: %d;\"%s\";%d;%d -> ",a_sysLogData->log_stat,a_sysLogData->log_tag,a_sysLogData->log_fac,a_sysLogData->log_mask);
}


// https://www.freebsd.org/cgi/man.cgi?query=malloc&sektion=3&manpath=FreeBSD+4.6-RELEASE
char * malloc_options = (char*)"";

__END_C_DECLS
