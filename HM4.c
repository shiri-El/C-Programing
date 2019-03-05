/*
Assignment: 4
Campus: Ashdod 
Author: Abudaram shiri, 


*/
#define _CRT_SECURE_NO_WARNINGS
#define KEY_CHAR_ENTER 10
#define WORD_SIZE 81
#define DEFINITION_SIZE 201
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void uppercase_lowercase_word(char *word, int first);
void lowercase_rest(char *word);
void uppercase_lowercase_defenition(char *text, int first);
void read_words(char ***dictionary, int *definition_counts, int num_words);
void uppercase_lowercase_dict(char ***dictionary, int *definition_counts,int num_words);
char *read_word();
char *read_definition();
void interact(char ***dictionary, int *definition_counts, int num_words);
void cleanup(char ***dictionary, int *definition_counts, int num_words);
void sort(char ***dictionary, int *definition_counts, int num_words,int start);
int remove_duplicates(char ***dictionary, int *definition_counts,int num_words);
void shift_place(char ***dictionary, int *definition_counts, int num_words,int start);
int find_word(char ***dictionary, int num_words, char *word);
int main(void)
{
	char ***dictionary;
	int *definition_counts;
	int num_words;
	//asking from the user the number of words to enter
	printf("plesase enter how many words you want to enter to the dictionary (number)\n");
	scanf("%d", &num_words);
	dictionary = (char***)malloc(sizeof(char **)*num_words);//set the size of the dictionary
	definition_counts = (int*)malloc(sizeof(int)*num_words);//set the numbers of the dictionary
	read_words(dictionary, definition_counts, num_words);//ask from the user the word and definition
	uppercase_lowercase_dict(dictionary, definition_counts, num_words);//fix the uppercase or lowercase
	sort(dictionary, definition_counts, num_words, 1);//sorting the words laxicografic
	num_words = remove_duplicates(dictionary, definition_counts, num_words);//remove duplicate
	dictionary = realloc(dictionary, sizeof(char **)*num_words);//set the new dictionary without the duplicates
	definition_counts = realloc(definition_counts, sizeof(int)*num_words);//set the new definitions after the delete of the duplicate
	interact(dictionary, definition_counts, num_words);//start to use the dictionary and look for words
	cleanup(dictionary, definition_counts, num_words);//clean the memory and all the definitions and the word
	return 0;
}

void sort(char ***dictionary, int *definition_counts, int num_words, int start)
{//sort the words from a to z
	if (start >= num_words)
		return;
	shift_place(dictionary, definition_counts, num_words, start);//call for the function that change the place of the word 
	sort(dictionary, definition_counts, num_words, start + 1);//call the fuction again with the next place of the word
}
void shift_place(char ***dictionary, int *definition_counts, int num_words, int start)
{
	char **tmp;
	int tmp_count;
	if (start == 0)
		return;
	if (strcmp(dictionary[start][0], dictionary[start - 1][0]) < 0)
	{
		tmp = dictionary[start];
		tmp_count = definition_counts[start];
		dictionary[start] = dictionary[start - 1];
		dictionary[start - 1] = tmp;
		definition_counts[start] = definition_counts[start - 1];
		definition_counts[start - 1] = tmp_count;
		shift_place(dictionary, definition_counts, num_words, start - 1);
	}
	else
		return;
}

int remove_duplicates(char ***dictionary, int *definition_counts, int num_words)
{//function that remove duplicates words
	int i, j;
	for (i = 0; i < num_words - 1;)
	{
		if (strcmp(dictionary[i][0], dictionary[i + 1][0]) == 0)
		{
			for (j = 0; j < definition_counts[i + 1] + 1; j++)
				free(dictionary[i + 1][j]);//if we find duplicate word  we delete the defenitions
			free(dictionary[i + 1]);//delete the duplicate word after we free the defenitions
			for (j = i + 1; j < num_words - 1; j++)
			{
				dictionary[j] = dictionary[j + 1];
				definition_counts[j] = definition_counts[j + 1];//set the new dictionary without duplicate
			}
			num_words--;
		}
		else
			i++;
	}
	return num_words;
}

void cleanup(char ***dictionary, int *definition_counts, int num_words)
{//free the dictionary and the definitions
	int i, j;
	for (i = 0; i < num_words; i++)
	{
		for (j = 0; j < definition_counts[i] + 1; j++)
			free(dictionary[i][j]);
		free(dictionary[i]);
	}
	free(dictionary);
	free(definition_counts);
}

int find_word(char ***dictionary, int num_words, char *word)
{//find the word in the dictionary
	int i;
	for (i = 0; i < num_words; i++)
	{
		if (strcmp(dictionary[i][0], word) == 0)
			return i;
	}
	return -1;
}

void interact(char ***dictionary, int *definition_counts, int num_words)
{//function that give the user the use of the dictionary 
	char *word;
	int place, j;
	//ask from the user  to enter a word to search or if he want to end the search
	printf("Enter word to search  or exit to end the use of the dictionary\n");
	Printf("make sure to enter the word with first letter uppercase and the rest of the word  lowercase letters\n")
	word = read_word();//look if the word is in the right size
	while (strcmp(word, "exit") != 0)
	{
		place = find_word(dictionary, num_words, word);
		if (place != -1)
		{
			for (j = 0; j < definition_counts[place]; j++)//printing the definitions of the word
				printf("Definition %d: %s\n", j + 1, dictionary[place][j + 1]);
		}
		else
			printf("word not found\n");
		free(word);
		printf("Enter word or exit\n");
		word = read_word();
	}
	free(word);
}

void read_words(char ***dictionary, int *definition_counts, int num_words)
{
	//function that ask from the user the amount of definitions for the word and set the word in the dictionary 
	int num_definitions;
	int i, j;
	for (i = 0; i < num_words; i++)
	{
		printf("please enter how many defenitions you will have for the %d  word\n",i+1);
		scanf("%d", &num_definitions);
		getchar();//seting the amount of defenitions in the dictionary
		dictionary[i] = malloc(sizeof(char *)*(num_definitions + 1));
		definition_counts[i] = num_definitions;
		printf("please enter the %d word\n",i+1);
		dictionary[i][0] = read_word();
		for (j = 0; j < num_definitions; j++)
		{
			printf("please enter the %d definition of the word\n",i+1);
			dictionary[i][j + 1] = read_definition();
		}
	}
}

char *read_word()
{//function that check the lenght of the word
	char word[WORD_SIZE];
	int i = 0;
	char c;
	char *ret;

	c = getchar();
	while (c != KEY_CHAR_ENTER)
	{
		if (i == WORD_SIZE-1)
			break;
		word[i] = c;
		i++;
		c = getchar();
	}//if the word is longer then 80 let the user know and ask for him to enter word again
	if (i == WORD_SIZE-1 && c != KEY_CHAR_ENTER)
	{
		printf("word longer than 80\n");
		return read_word();
	}
	word[i] = '\0';
	ret = (char*)malloc(sizeof(char)*(1 + i));
	strcpy(ret, word);
	return ret;
}

char *read_definition()
{//make sure that the user enter definitions with the right size
	char word[DEFINITION_SIZE];
	int i = 0;
	char c;
	char *ret;

	c = getchar();
	while (c != KEY_CHAR_ENTER)
	{
		if (i == WORD_SIZE-1)
			break;
		word[i] = c;
		i++;
		c = getchar();
	}
	if (i == WORD_SIZE-1 && c != KEY_CHAR_ENTER)
	{
		printf("defintion longer than 200 letters\n");
		return read_word();
	}
	word[i] = '\0';
	ret =(char*) malloc(sizeof(char)*(1 + i));
	strcpy(ret, word);
	return ret;
}

void uppercase_lowercase_word(char *word, int first)
{//change the word to be uppercase or lowercase
	if (word[0] == '\0')
		return;
	if (first && word[0] >= 'a' && word[0] <= 'z')
		word[0] += 'A' - 'a';
	if (!first && word[0] >= 'A' && word[0] <= 'Z')
		word[0] += 'a' - 'A';
	uppercase_lowercase_word(word + 1, 0);
}

void uppercase_lowercase_defenition(char *text, int first)
{
	//change the word defenition to be uppercase or lowercase

	int next_first = first;
	if (text[0] == '\0')
		return;
	if (first && ((text[0] >= 'a' && text[0] <= 'z') ||
		(text[0] >= 'A' && text[0] <= 'Z')))
	{
		if (text[0] >= 'a' && text[0] <= 'z')
			text[0] += 'A' - 'a';
		next_first = 0;
	}
	else if (!first && text[0] >= 'A' && text[0] <= 'Z')
		text[0] += 'a' - 'A';
	else if (text[0] == '.')
		next_first = 1;
	uppercase_lowercase_defenition(text + 1, next_first);
}

void uppercase_lowercase_dict(char ***dictionary, int *definition_counts, int num_words)
{//set the word in the divtionery uppercase or lowercase words
	int i, j;
	for (i = 0; i < num_words; i++)
	{//call for the word fix function
		uppercase_lowercase_word(dictionary[i][0], 1);
		for (j = 0; j < definition_counts[i]; j++)//call for the defenition fix word function
			uppercase_lowercase_defenition(dictionary[i][j + 1], 1);
	}
}
