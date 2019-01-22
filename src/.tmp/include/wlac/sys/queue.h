#pragma once

#ifdef __cplusplus
#define STRUCTDEF
#else
#define STRUCTDEF	struct
#endif


#define TAILQ_ENTRY(_type)			STRUCTDEF _type *
#define TAILQ_HEAD(_unknown,_type)	STRUCTDEF _type * _unknown
