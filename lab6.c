#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int* insertArray(int[]);
int* minimizeArray(int []);
char* str_cut(char[]);
int* num_to_str();
int main()
{
	/*int size;
	printf("enter size\n");
	scanf("%d", size);
	int *ptr_arr = init(size);
	if (!ptr_arr)
	{
		printf("no array\n");
		return 0;
	}
	for (int i = 0; i < size; ++i)
	{
		printf("%d", ptr_arr[i]);
	}
	free(ptr_arr);
	return 0;
	int* arr = NULL;
	insertArray(arr);*/
	return 0;
}
/*////question 1.a/////
int* insertArray(int arr[])
{
	int size = 0;
	int* numbers = NULL;
	printf("enter the ampount of numbers your about to enter\n");
	scanf("%d", &size);
	numbers = (int*)malloc((size + 1) * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		scanf("%d", numbers + i);
	}
	*(numbers + size) = '\0';

}
///question 1.b/////
int* minimizeArray(int NUM[])
{
	int i,j=0, len;
	prntf("enter the size of the array\n");
	scanf("%d", &len);
	int* EVEN = NULL;
	EVEN =(int*)malloc(((len)* sizeof(int)));
	for (i = 0; i < len; i++) {
		//5
		if (NUM[i] % 2 == 0) {
			EVEN[j] = NUM[i];
			j++;
		}
		
	}
	if(!EVEN)
	{
		free(EVEN);
		return NUM;
	}
	return EVEN;

}
/////question 1.c//////
int* init(int size)
{
	int* arr = NULL;
	arr = (int*)malloc((size) * sizeof(int));
	if (!arr)
	{
		return arr;
	}
	for (int i = 0; i < size; ++i)
		scanf("%d", &arr[i]);
	return arr;
}
/////question 2/////
char* str_cut(char* name)
{

	int i,len = 0;
	printf("enter len\n");
	scanf("%d", len);
	char*temp = NULL;
	temp = (char*)malloc((len + 1)*sizeof(char));
	if (!temp)
	{
		free(name);
		exit(1);
	}
	for (i; i < name[i]; i++)
	{
		temp[i] = name[i];
	}
	temp[i] = ' ';
	printf("enter last name\n");
	for (i = i + 1; i < len; i++)
	{
		scanf("%c", &temp[i]);
	}
	temp[len] = '\0';
	if (name)
		free(name);
	name = temp;
	temp = NULL;
	puts(name);
}
*/
////question 3/////
int* num_to_str()
{
	int number,count,temp,i = 0;
	int* arr_number = NULL;
	printf("please enter intager\n");
	scanf("%d", &number);

	while (number != 0)
	{
		count++;
		temp = (number % 10);
		number /= 10;
	}
	arr_number = (int*)malloc((count) * sizeof(int));
	for (i; i < count; i++)
	{
		arr_number[i] = (temp % 10);
		temp /= 10;
	}
	return *arr_number;

}
