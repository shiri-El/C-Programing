/*assignment : 1
author : Abudaram Shiri
Id: 032552945*/

/*


//////////////FIRST QUESTION////////////////

#define _CRT_SECURE_NO_WARNINGS
#define FIRSTPRICE  10.20
#define KMPRICE 1.30
#define LAUGEGEPRICE 2.00
#include <stdio.h>

int main()
{
	float Distance,Payment= 0;
	int NumberOfLaugege = 0;
	//asking the user to enter information about the drive//
	printf("please enter the distance you want to travle\n");
	scanf("%f", &Distance);
	//asking the user to enter information about the drive
	printf("please enter the number ot laugege you travel with\n");
	scanf("%d", &NumberOfLaugege);
	getchar();
	//checking if the input is corect//
	if (NumberOfLaugege == 0)
		Payment = ((Distance*KMPRICE) + FIRSTPRICE);
	if(Distance == 0)
			printf("apperently you are not going anywhere\n"); 
	if ((NumberOfLaugege > 0) && (Distance > 0))
			Payment = ((Distance*KMPRICE) + (NumberOfLaugege*LAUGEGEPRICE) + FIRSTPRICE);
	//printing the payment//		
	printf("The payment is: %.2f\n", Payment);
	return 0;
}
*/

/*

//////SECONED QUESTION//////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
//geting input from user//
	int side1, side2, side3 = 0;
	printf("please enter side 1 of the triangle\n");
	scanf("%d", &side1);
	printf("please enter side 2 of the triangle\n");
	scanf("%d", &side2);
	printf("please enter the base of the triangle\n");
	scanf("%d", &side3);
	//checking if the triangle is equilateral or isosceles or if the input is corect//
	if ((side1 > 0) && (side2 > 0) && (side3 > 0))
	{
		if ((side1 == side2) && (side1 == side3))
			printf("the triangle is equilateral\n ");
		if ((side1 == side2) && (side1 != side3))
			printf("the triiangle is isosceles triangle\n");
		if ((side1 != side2) && (side2 != side3))
			printf("the triangle has diffrent ribs\n");
	}
	else
		printf("the input is not right there is not a triangle such as this type\n");

	return 0;
}*/

/*
/////////////THERED QUESTION//////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef enum
{
	Jan = 1,
	Feb = 2,
	Mar = 3,
	Apr = 4,
	May = 5,
	Jun = 6,
	Jul = 7,
	Aug = 8,
	Sep = 9,
	Oct = 10,
	Nov = 11,
	Dec = 12
}  Month;
int main()
{
	int  day, year = 0;
	Month MonthInput;
	printf("please enter a date to check\n");

	//getting input from the user//

	printf("enter the year in the patern of YYYY\n");
	scanf("%d", &year);
	printf("enter the month of the year you entered\n");
	scanf("%d", &MonthInput);
	printf("enter the day in the month you entered\n");
	scanf("%d", &day);

	//check if the year that the user entered  is correct//


	if (year >= 1900)
	{
		switch (MonthInput)
		{
		//check if the day entered is correct//
		case 1:
			if ((day >= 1) || (day <= 31)) {
				printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);
			}
			else
			{
				printf("incorrect date (invalid: day %d month %d)    \n",day,MonthInput);
			}
			break;
		case 2:
			//check if the day is correct//
			if ((day >= 1) && (day <= 29))
			{
				//check if the year is Leap year//
				if ((((day > 28) && (year % 4 == 0) && (year % 100 != 0)) || ((day > 28) && (year % 400 == 0)))||(day<=28))
					printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);				else
				{
					printf("incorrect date (invalid: day %d month %d)    \n",day,MonthInput);
				}
			}
			else
				printf("incorrect date(invalid: day % d month %d)    \n",day,MonthInput);
			break;
		case 3:
			//check if the day is correct//
			if ((day >= 1) || (day <= 31)) {
				printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);
			}
			else
			{
				printf("incorrect date (invalid: day %d month %d)    \n", day, MonthInput);
			}
			break;
		case 4:
			//check if the day is correct//
			if ((day >= 1) || (day <= 30)) {
				printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);
			}
			else
			{
				printf("incorrect date (invalid: day %d month %d)    \n", day, MonthInput);
			}
			break;
		case 5:
			//check if the day is correct//
			if ((day >= 1) || (day <= 31)) {
				printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);
			}
			else
			{
				printf("incorrect date (invalid: day %d month %d)    \n", day, MonthInput);
			}
			break;
		case 6:
			//check if the day is correct//
			if ((day >= 1) || (day <= 30)) {
				printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);
			}
			else
			{
				printf("incorrect date (invalid: day %d month %d)    \n", day, MonthInput);
			}
			break;
		case 7:
			//check if the day is correct//
			if ((day >= 1) || (day <= 31)) {
				printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);
			}
			else
			{
				printf("incorrect date (invalid: day %d month %d)    \n", day, MonthInput);
			}
			break;
		case 8:
			//check if the day is correct//
			if ((day >= 1) || (day <= 31)) {
				printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);
			}
			else
			{
				printf("incorrect date (invalid: day %d month %d)    \n", day, MonthInput);
			}
			break;
		case 9:
			//check if the day is correct//
			if ((day >= 1) || (day <= 30)) {
				printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);
			}
			else
			{
				printf("incorrect date (invalid: day %d month %d)    \n", day, MonthInput);
			}
			break;
		case 10:
			//check if the day is correct//
			if ((day >= 1) || (day <= 31)) {
				printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);
			}
			else
			{
				printf("incorrect date (invalid: day %d month %d)    \n", day, MonthInput);
			}
			break;
		case 11:
			//check if the day is correct//
			if ((day >= 1) || (day <= 30)) {
				printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);
			}
			else
			{
				printf("incorrect date (invalid: day %d month %d)    \n", day, MonthInput);
			}
			break;
		case 12:
			//check if the day is correct//
			if ((day >= 1) || (day <= 31)) {
				printf("the date you entered is correct - \n %d/%d/%d \n", day, MonthInput, year);
			}
			else
			{
				printf("incorrect date (invalid: day %d month %d)    \n", day, MonthInput);
			}
			break;
			///if the month that the user entered is not correct///
		default: if (MonthInput > 12 || MonthInput < 1)
		{
			printf("the month %d you entered is not corect\n",MonthInput);
		}
				 break;
		}
	}
	//if the year that the user entered is not correct//
	else
		printf("the year %d you entered is not corect \n",year);

	return 0;
	
	
}
*/


//////////FORTH QUESTION - SWITCH CASE TYPE//////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char SignInput = 0;
	int operand1, operand2, sulotion = 0;
	float Divited = 0;
	//asking for input from the user//
	printf("please enter an operation (  + , - , / , %% ) \n ");
	scanf("%c", &SignInput);
	printf("please enter the first operand \n");
	scanf("%d", &operand1);
	printf("please enter the seconed operand \n");
	scanf("%d", &operand2);

	switch (SignInput)
	{
	case 37:
	//convert int to float///
		Divited = (float)(operand1%operand2);
		printf("i am clever calculator: %d %% %d = %.2f", operand1, operand2,  Divited);
		break;
	case 42:
		sulotion = (operand1*operand2);
		printf("i am clever calculator: %d * %d = %d", operand1, operand2, sulotion);
		break;
	case 43:
		sulotion = (operand1 + operand2);
		printf("i am clever calculator: %d + %d = %d", operand1, operand2, sulotion);
		break;
	case 45:
		sulotion = (operand1 - operand2);

		printf("i am clever calculator: %d - %d = %d", operand1, operand2, sulotion);
	
		break;
	case 47:
		////47 in ascii is "/" ///
		//check if the user is not dividing by zero///
		if (operand2 > 0)
		{
		//convert int to float///
			Divited = (operand1 / (float)operand2);
			printf("i am clever calculator: %d / %d = %.2f", operand1, operand2, Divited);
		}
		else
		{
			printf("you are not alow to divited by ZERO!!\n");
		}
		break;
		///check if the sign is correct///
	default: if ((SignInput!='+')||(SignInput!='-')||(SignInput!='/')||(SignInput!='%%')||(SignInput!='*'))
	{
		printf("your input is incorrect! \n");
		break;
	}

	}
	return 0;
}

/*
//////////FORTH QUESTION - IF-ELSE TYPE//////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{

	char SignInput = 0;
	int operand1, operand2, sulotion = 0;
	float Divited = 0;
	///asking from the user input///
	printf("please enter an operation (  + , - , / , %% ) \n ");
	scanf("%c", &SignInput);
	printf("please enter the first operand \n");
	scanf("%d", &operand1);
	printf("please enter the seconed operand \n");
	scanf("%d", &operand2);
	///check if the sign is correct
	if ((SignInput != '+') || (SignInput != '-') || (SignInput != '/') || (SignInput != '%%')||(SignInput!='*'))
	{
		printf("Your input is incorrect! \n");
	}
	else
	{
		//check what input the user entered///
		if (SignInput == '+') {
			sulotion = (operand1 + operand2);
			printf("i am clever calculator: %d + %d = %d", operand1, operand2, sulotion);
		}

		if (SignInput == '-') {
			sulotion = (operand1 - operand2);
			printf("i am clever calculator: %d - %d = %d", operand1, operand2, sulotion);
		}

		if (SignInput == '*') {
			sulotion = (operand1 * operand2);
			printf("i am clever calculator: %d * %d = %d", operand1, operand2, sulotion);
		}

		if (SignInput == '/') {
			///check that the user is not divited by zero///
			if (operand2 == 0)
			{
				printf("you trying to divited by ZERO!!\n");
			}
			else {
				////convert int to float////
				Divited = (operand1 /(float) operand2);
				printf("i am clever calculator: %d / %d = %.2f", operand1, operand2, Divited);
			}

			if (SignInput == '%%') {
				///convert int to float////
				Divited =(float) (operand1 % operand2);
				printf("i am clever calculator: %d %% %d = %.2f", operand1, operand2, Divited);
			}
		}
	}
	return 0;
}
*/