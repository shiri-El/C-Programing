#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*lab 2 mission 1
int main()
{
	int num1, num2,CheckNum = 0;
	printf("please enter 2 positiv numbers \n");
	printf("please enter the first number \n");
	scanf("%d", &num1);
	printf("please enter the second number \n");
	scanf("%d", &num2);
	if (num1%num2 == 0)
	{
		printf("the number is divited %d", num1 / num2);

	}
	else
	{
		printf("the number is not divited %d", num1%num2);
	}

	return 0;
}
*/
/*lab2 mission2
int main()
{
	int num1, num2, num3= 0;
	printf("please enter 3 numbers\n");
	printf("please enter the first number \n");
	scanf("%d", &num1);
	printf("please enter the second number \n");
	scanf("%d", &num2);
	printf("please enter the thered number \n");
	scanf("%d", &num3);
	if (num1 > num2 && num2 > num3)
	{
		printf("ascending \n");
	}
	else if (num1 < num2 && num2 < num3)
	{
		printf("descending \n");
	}
	else
	{
		printf("not sorted \n");
	}

	return 0;
}
*/
/*lab2 mission 3
int main()
{
	int number, digit1,digit2,digit3,digit4=0;
	printf("please enter 4 digit number \n");
	scanf("%d", &number);
	digit1 = number % 10;
	printf("%d\n", digit1);
	digit2 = number/10%10;
	printf("%d\n", digit2);
	digit3 = number/ 100%10;
	printf("%d\n", digit3);
	digit4 = number/1000%10;
	printf("%d\n", digit4);
	if ((digit1 == digit4) && (digit2 == digit3))
	{
		printf("number symmetrical\n");
	}
	else
	{
		printf("non symetrical number \n");
	}
	return 0;
}
*/

/*lab2 miision 4
int main()
{
	int num1, num2,num3 = 0;
	printf("please enter 3 numbers\n");
	printf("please enter the first number\n");
	scanf("%d", &num1);
	printf("please enter the second number\n");
	scanf("%d", &num2);
	printf("please enter the thered number\n");
	scanf("%d", &num3);
	if ((num1 > num2) && (num2 > num3))
	{
		printf("%d\n%d\n%d\n", num3, num2, num1);
	}
	else if ((num3 > num2) && (num2 > num1))
	{
		printf("%d\n%d\n%d\n", num1, num2, num3);
	}
	else if ((num2 > num1) && (num1 < num3))
		{
			printf("%d\n%d\n%d\n",num1,num3,num2);
		}
	return 0;

}
*/

/*lab2 SWITCH_CASE*/
int main()
{

	enum Month{jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};
	{
		int number = 0;
		printf("please enter month\n");
		scanf
		switch (number)
		{
		case 1: 
			printf("there are 31 day's in january\n");
			break;
		case2:
			printf("there are 28 day's in feb\n");
			break;
		case 3:
			printf("there are 31 day's in mar\n");
			break;
		case 4:
			printf("there are 30 day's in apr\n");
			break;
		case 5:
			printf("there are 31 day's in may\n");
			break;
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		default:
			printf("enter number not valid\n");
			break;
		}

	};
}