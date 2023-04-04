#include <stdio.h>
#include <conio.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	setlocale(LC_ALL, "RUS");
	int a;
	printf("¬ведите целое дес€тичное число: ");
	scanf_s("%d", &a);
	perevod(a);
}

int perevod(int number)
{
	int a,i;
	int i = 0;
	if (number > 0) {
		for (int i = 0; i < a; i++)
		{
			
		}

		int i = 0;
		while (number != 0)         
		{
			if (number % 2 == 0)
			{
				int i = 0;
			}
			else
			{
				int i = 1;

			}
			number = number / 2;
			i++;
		}


		printf("„исло в двоичной системе счислени€: ");
		
		i = i - 1;                
		for (; i >= 0; i--) {
			printf("%d");
		}
	}
	else if ((number < 0) and (number == 0)) {
		printf("¬веденное вами число меньше или равно нулю");
	}


	return 0;
}

