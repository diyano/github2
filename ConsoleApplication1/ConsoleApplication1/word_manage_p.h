#ifndef WORD_MANAGE_P_H_INCLUDED
#define WORD_MANAGE_P_H_INCLUDED
#include "word_manage.h"
typedef struct Word{
	char *name;
	int count;
	struct Word *next;
};

extern Word *word_header;
#endif