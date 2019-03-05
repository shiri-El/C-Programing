/*assignment : 2
author : Abudaram Shiri
*/

/*



#define _CRT_SECURE_NO_WARNINGS
#define ARR1SIZE 15
#define ARR2SIZE 10
#define MAXSTRING 100
#define MAXROW 10
#define MAXCOL 7
#define MAXVALUE 100
#define MINVALUE 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void PrintMenu();
void Array();
void ArrayMenu(int[]);
int MissingNumber(int []);
void String();
void StringMenu(char[]);
char InttoVal(char[]);
char Issentence(char[]);
void Matrix();
void InsertMatri();
void printMatrix(float[][MAXCOL]);
float summingMatrix(float[][MAXCOL]);
void InsertRandMatri();
int main()
{
	srand(time(NULL));// Initialization of random
	PrintMenu();

	return 0;
}
///array case
void PrintMenu() {
	char option,garbege= 0;

		////printing the main menu////
		do {
			printf("please enter you'r option to do with the array:\n");
			printf("A-Array stufff\n");
			printf("S-String stuff\n");
			printf("M - Matrix 2 demantions\n");
			printf("E - Exit  back to main menu\n");
			scanf("%c", &option);
			switch (option)
			{
			case 'A':
			case 'a':
				//working with arrays///
				Array();
				break;
			case 'S':
			case 's':
				String();
				break;
			 case 'M':
			 case 'm':Matrix();
				break;
			default:(!('a' || 'A') || !('s' || 'S') || !('m' || 'M'));
				break;
			}
		} while (option!='a'||option!='A'||option!='s'||option!='S'||option!='m'||option!='M' );
	}
void Array()
	{
		int arr1[ARR1SIZE] = { 0 }, arr2[ARR2SIZE] = { 0 }, counter1 = 0, index = 0, value = ARR1SIZE, Temp = 0;
		
		do
		{
			for (index=0; index < ARR1SIZE; ++index)
			{
				printf("please enter %d numbers to the array\n",value);
				scanf("%d", &Temp);
				if (Temp > 0)//check that the input is not zero
				{
					arr1[index] = Temp;
					++counter1;//counting how many digit the user entered
					value--;
				}
				if (index < ARR1SIZE&&Temp == 0)//if the user entered 0 we end the recuest for input and put zero in the place in the array
				{
					arr1[index] = Temp;
					index = ARR1SIZE;
					++counter1;
				}
			}
		}while ((index < ARR1SIZE && Temp > 0));///continue to ask for digits as long as it in the range
		ArrayMenu(arr1);
	};
void ArrayMenu(int arr1[]) {
		int index=0, counter1=ARR1SIZE,counter2=0, total, Temp = 0;
		int arr2[ARR2SIZE] = { 0 };
		char garbege=0,OptionInArray =0;
		///printing menu/////
		printf("please enter you'r option to do with the array:\n");
		printf("L - Eliminate Double Numbers\n");
		printf("M - Missing Value\n");
		printf("D - Dominant Array\n");
		printf("E - Back To Main Menu\n");
		scanf("%c", &garbege);
		scanf("%c",&OptionInArray);
		switch (OptionInArray)
		{
			case 'L':///check for double difit in the array and eliminate them
			case 'l':
				for (index = 0; index < counter1; index++)
				{
					for (int j = index+1; j < counter1; )
					{
						if (arr1[j] == arr1[index])
						{
							for (int k = j; k < counter1; k++) 
							{
								arr1[k] = arr1[k + 1];
								
							}
							counter1--;
							counter2++;
						}
						else
						{
							j++;
						}
					}
				}
				///printing the new array
				printf("the new array without double digits is:\n");
				for (index = 0;index < counter1; index++)
				{
					printf("%d \n",arr1[index]);
				}
				ArrayMenu(arr1);
				break;
			case 'm':
			case 'M':
				total = MissingNumber(arr1);
				printf("the miising number is: %d\n", total);//printing the result from the function
				ArrayMenu(arr1);
				break;
			case 'd':
			case 'D':
				counter2 = 0;
				do
				{
					for (index = 0; index < ARR2SIZE; ++index)
					{
						printf("please enter numbers to the array\n");
						scanf("%d", &Temp);
						if (Temp > 0)//check that the input is not zero
						{
							arr2[index] = Temp;
							++counter2;//counting how many digit the user entered
						}
						if (index < ARR2SIZE&&Temp == 0)//if the user entered 0 we end the recuest for input and put zero in the place in the array
						{
							arr2[index] = Temp;
							index = ARR2SIZE;
							++counter2;
						}
					}
				} while ((index < ARR2SIZE && Temp > 0));///continue to ask for digits as long as it in the range
				int max = arr2[0];//set the max digit of the second array
				for (index = 1; index < counter2; index++)
				{
					if (arr2[index] > max)//if the next digit in the array is bigger then max the swap
						max = arr2[index];
				}

				for (index = 0; arr1[index] != 0; index++)//check if first array dominant
				{
					if (arr1[index] < max)//if there is digit from the first array that smaller then second array print and break
					{
						printf("the first array is not dominant\n");
						break;
					}

				}
				//if the first array is dominant
				printf("the first array is dominant\n");
				ArrayMenu(arr1);

				break;
			case 'e':
			case'E':
				PrintMenu();
				break;
			default:(!('m' || 'M') || !('d' || 'D') || !('e' || 'E') || !('l' || "L"));
				break;
			}
	     }
int MissingNumber(int arr[])
	{
		int index,size=0, total = 0;
		for (index = 0; arr[index]!='\0'; index++)
		{
			size++;
		}
		printf("the size of the array is %d\n", size+1);
		total = (size + 1)*(size + 2) / 2;//count the digits in the array and get the sum of the total arrays digits
		for (index = 0; index < size; index++)
		{
			total -= arr[index];//sub the digit from the total so the reminder will be the missing number
		}
		return total;
	}
void String()
{
	char string1[MAXSTRING];
	printf("please enter the string\n");
	scanf("%s", &string1);
	StringMenu(string1);
}
void StringMenu(char str[])
{ 
	char option = 0 , result = 0,garbege = 0;
		////printing the main menu////
	scanf("%c", &garbege);
	printf("please enter you'r option to do with the String:\n");
    printf("I-String to int value\n");
	printf("S-String is sentence\n");
	printf("E - Exit back to main menu\n");
	scanf("%c", &option);
	switch (option)
	{
		case 'I':
		case 'i'://call to the function and return the result to the menu and print it
				result = InttoVal(str);
				if (result == -1)//check if the user entered numbers or letters.
				{
					printf("there are no numbers in the string\n");
				}
				else
				{//if the user entered numbers print it to the screan
					printf("the number you entered to the string is:\n%d\n", result);
				}
				scanf("%c", &garbege);
				StringMenu(str);
				break;
		case 'S':
		case 's'://call to function that check if the string is sentence
				result = Issentence(str);
				if (result == 0)//the sentence start with capital letter end with '.'and all the rest of the letters are small 
						printf("the string you entered is a sentence\n");
				else
				{//not standing with the rulse
				printf("the string is not a sentence\n");
				}
				scanf("%c", &garbege);
				StringMenu(str);
						break;
		case 'E':
		case 'e':
		PrintMenu();
		break;
		default:(!('i' || 'I') || !('S' || 's') || !('e' || 'E'));
		break;
	}
}
char InttoVal(char str[])
	{
		int index=0,temp=0 ,isDigit=0;
		while (index !='\0'&&isDigit == 0)
		{
			if ((str[index] > 0 && str[index] < 9)||(str[index]==' '))
			{
				temp *= 10 + (str[index]-'0');
				++index;
			}
			else
			{
				if (temp == 0)
				{
					isDigit = 1;
					return -1;
				}
				
			}
		}
		return temp;
	}
char Issentence(char str[])
	{
		int index=0,bool = 0,size=MAXSTRING;
		if (str[0] >= 'A' || str[0] <= 'Z')
		{
			++index;	

			for (index = 1; (index < MAXSTRING) && (str[index] != '\0'); index++)
			{
				if ((str[index] > 'a' || str[index] < 'z') || (str[index] == ' '))
				{
					if ((str[index] == ' ') && (str[index - 1] > 'a' || str[index - 1] < 'z') && (str[index + 1] > 'a' || str[index + 1] < 'z'))
						++index;
					++index;
				}
				else
				{
					bool = 1;
				}
			}
		}
		else
			bool = 1;
			if (str[index-1] == '.')  
			{
				if((str[index - 2] != ' ') || bool == 0)
					return bool;
				return bool;
			}
			else
				bool = 1;
		return bool;
	}
void Matrix()
	{
		//menu for the matrix choice
		char option,garbege = 0;
		printf("please cose your option\n");
		printf("M - for manual insert the array\n");
		printf("R - for randomal insert\n");
		scanf("%c", &garbege);
		scanf("%c", &option);
		switch (option)
		{
		case 'M':
		case'm'://insert the matrix menual
			InsertMatri();
			break;
		case 'R':
		case 'r'://insert the matrix randomal
			InsertRandMatri();
			break;
		default:(!('m' || 'M') || !('r' || 'R'));
			break;
		}
	}
void InsertMatri()
	{//function that fill the matrix with numbers
		float mat[MAXROW][MAXCOL];
		float temp = 0;
		float result = 0;
		int num = 1;
		for (int row = 0; row < MAXROW; ++row)
		{
			for (int col = 0; col < MAXCOL; ++col)
			{
				//ask from the user input
				printf("enter %d form 70 values to array\n",num);
				scanf("%f", &temp);
				mat[row][col] = temp;
				num++;
			}
		}
		printMatrix(mat);//call the function that print the matrix
		result =(float) summingMatrix(mat);
		printf("the sum of the matrix is:%.2f\n", result);//printing the summing of the matrix
		PrintMenu();
	}
void printMatrix(float mat[][MAXCOL])
	{//function that print the matrix
	printf("the matrix is:\n");
		for (int row = 0; row < MAXROW; row++) 
		{
			for (int col = 0; col < MAXCOL; col++) {
				printf("%.2f     ", mat[row][col]);
			}
			printf(")\n");
		}
		
	}
float summingMatrix(float mat[MAXROW][MAXCOL])
	{ //function that summing the matrix
		int row, col= 0;
		float sum = 0;
		for (row=0; row < MAXROW; row++)
		{
			for (col=0; col < MAXCOL; col++)
			{
				sum +=(float) mat[row][col];//summint the numbers
			}
		}
		return sum;
	}
void InsertRandMatri()
	{
		float mat[MAXROW][MAXCOL];
		float result = 0;
		float value = (rand() % (MAXVALUE - MINVALUE + 1)) + MINVALUE;

		for (int row = 0; row < MAXROW; ++row)//fill the matrix with random values
		{
			for (int col = 0; col < MAXCOL; ++col)
			{
				mat[row][col] = (float)value;
			}
		}
		printMatrix(mat);//call for the print function
		result = summingMatrix(mat);//summing the matrix and print the result
		printf("the sum of the matrix is:%.2f\n", result);//printing the summing of the matrix
		PrintMenu();//back to the main menu
	}
