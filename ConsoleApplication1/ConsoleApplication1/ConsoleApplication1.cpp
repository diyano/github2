// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define yes 1
#define no 0
int htoi(char s[])
{
	int hexdigit, i, inhex, n;
	i = 0;
	if (s[i] == '0'){
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}
	n = 0;
	inhex = yes;
	for (; inhex == yes; ++i){
		if (s[i] >= '0'&&s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a'&&s[i] <= 'f')
			hexdigit = s[i] - 'a'+10;
		else if (s[i] >= 'A'&&s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
			inhex = no;
		if (inhex == yes)
			n = n * 16 + hexdigit;

	}
	return n;

}

int lower(int c)
{
	if (c >= 'A'&&c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

//squeeze
void squeeze1(char s[], int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++){
		if (s[i] != c)
			s[j++] = s[i];
	}
	s[j] = '\0';
}

void squeeze2(char s[], char t[])
{
	int i, j, k;
		for (i = j = 0; s[i] != '\0'; i++){
		
			for (k = 0; t[k] != '\0'&&t[k] != s[i]; k++)
				;
			if (t[k] == '\0')
			s[j++] = s[i];
	}
	s[j] = '\0';


}

void strcat(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0')
		;
}

int any(char s[], char t[]){

	int i, j;
	for (j = 0; t[j] != '\0'; j++){
	for (i = 0; s[i] != '\0'; i++){
		if (s[i] == t[j])
			return i;
	}
}
	return -1;
}
int lower2(int c)
{
	int d;
	(c >= 'A'&&c <= 'Z') ? d = c + 'a' - 'A' : d = c;

	return d;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid + 1;
		else if (x>v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int atoi(char s[]){
	int i, n, sign;
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign*n;

}

// shellsort
void shellsort(int v[], int n){
	int gap, i, j, temp;
	for (gap = n / 2; gap > 0;gap/=2)
	   for (i = gap; i < n; i++)
	   for (j = i - gap; j >= 0 && v[j]>v[j + gap]; j -= gap){
		   temp = v[j];
		   v[j] = v[j + gap];
		   v[j + gap] = temp;
	   }
}


void reverse(char s[]){
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

}
int main( )
{
	char c[] = "123";
	int s[3] = { 3, 1, 2 };
	int i;
	reverse(c);

		printf("%s\n",c);




	return 0;
}

