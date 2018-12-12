#define _CRT_SECURE_NO_WARNINGS
#define SIZEOFSTR 80
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void Min_Max(int, int*, int*);
void SizeOfString(char *str);
void Sort(int * x, int * y, int * z);
int main()
{
	/*////Question 1/////
	int number,minimun,maximum = 0;
	printf("please enter a number\n");
	scanf("%d", &number);
	Min_Max(number, &minimun, &maximum);
	printf("Min Digit:%d\n", minimun);
	printf("Max Digit:%d\n", maximum);*/

	/*///Question 2//
	char string[SIZEOFSTR];
	printf("please enter a string\n");
	scanf("%s", &string);
	SizeOfString(&string);
	*/

	/*//Question 3//
	int num1, num2, num3 = 0;
	printf("please enter 3 numbers\n");
	printf("please enter the 1 number\n");
	scanf("%d", &num1);

	printf("please enter the 2 number\n");
	scanf("%d", &num2);

	printf("please enter the 3 number\n");
	scanf("%d", &num3);
	Sort(&num1, &num2, &num3);
	*/



}
void Min_Max(int num, int *min, int *max)
{
	int digit = 0;
	*min = num % 10; //grab last digit
	*max = num % 10;//grab last digit
	while (num != 0) {
		   
		digit = (num % 10);        //throw last digit away
		       
		if (*max < digit) {      //if this digit is grater than current max...
			*max = digit;  //... update it!
		}
		if(*min>digit)
			*min = digit;   //update it!
		num = (num / 10);
	}
	
}

void SizeOfString(char *str) {
	int size = sizeof(str) / sizeof(char);
	printf("the size of the string is:%d\n", size);
}

void Sort(int * x, int * y, int * z)
{
	
	if (((*x < *y) && (*x < *z)) && (*y < *z))
	{//3 5 8
		printf("%d\t%d\t%d\n", *z, *y,*x);
	}
	if ((*x > *z) && (*y < *z))
	{
		//8 2 6
		printf("%d\t%d\t%d\n", *x, *z, *y);
	}
	if ((*x > *z) && (*y < *z))
	{
		//6 8 2
		printf("%d\t%d\t%d\n", *y, *x, *z);
	}
}
