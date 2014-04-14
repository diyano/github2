#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int get_word(char *buf,int buf_size,FILE *fp)
{
	int len;
	int ch;
	char l;
	while ((ch = getc(fp)) != EOF&&!isalnum(ch))//去除前面的空格
		;
	if (ch == EOF)
		return EOF;
	l = (char)ch;
	len = 0;	
		buf[len] = (char)ch;
		len++;
		if (len >= buf_size){
			fprintf(stderr, "word too long.\n");
			exit(1);
		}
	buf[len] = '\0';
	return len;
} 