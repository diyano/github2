// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。


#include<stdio.h>
#include<stdlib.h>
#include"get_word.h"
#include"word_manage.h"
#define WORD_LEN_MAX (1024)


int main(int argc, char **argv){
	char buf[WORD_LEN_MAX];
	FILE * fp;
	if (argc == 1){
		//fp = stdin;
		fp = fopen("123.txt", "r");
	}
	else{
		fp = fopen(argv[1], "r");
		if (fp == NULL){
			fprintf(stderr, "%s:%s can not open.\n", argv[0], argv[1]);
			exit(1);
		}
	}

	word_initialize();

	while (get_word(buf, WORD_LEN_MAX, fp) != EOF){
		add_word(buf);
	}
	dump_word(stdout);
	word_finalize();
	return 0;
}

//
//#include <stdio.h> 
//#include<process.h> 
//int main()
//{
//	char buffer[81];
//	int i, ch;
//	FILE* fp;
//
//	// Read a single line from the file "crt_getc.txt". 
//
//	fopen_s(&fp, "123.txt", "r");
//	if (!fp)
//	{
//		printf("Failed to open file 123.txt.\n");
//		exit(1);
//	}
//
//	for (i = 0; (i < 80) && ((ch = getc(fp)) != EOF)
//		&& (ch != '\n'); i++)
//	{
//		buffer[i] = (char)ch;
//	}
//
//	// Terminate string with a null character 
//	buffer[i] = '\0';
//	printf("Input was: %s\n", buffer);
//	fclose(fp);
//
//}
