#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** words(int);
typedef enum {FALS,TRUE} boolean;
int main()
{
	int size;
	char** p2 = NULL;
	scanf("%s", &size);
	p2=words(size);
	printString(p2, size);

	return 0;
}
char** words(int size)
{
	char **p1=NULL, buffer[30];
	
	p1 = (char **)malloc(size*sizeof(char*));
	if (p1 == NULL)
	{
		return p1;
	}
	
	for (int i = 0; i <= size; i++)
	{
		printf("Enter string\n");
		scanf("%s", buffer);
		p1[i] = (char*)malloc(strlen(buffer) + 1);
		if (p1[i] == NULL)
		{
			myfree(p1, i-1);
			free(p1);

			return NULL;

		}
		strcpy(p1[i], buffer);
	}
	
	
	return p1;
}
boolean myfree(char**words, int size)
{
	for (size; size >= 0; --size)
	{
		free(words[size]);
	}
	return TRUE;
}
void printString(char** word,int size)
{
	int i = 0;
	for (i = 0; 1 < size; i++)
	{
		printf("%s\n", word[i]);
	}

}