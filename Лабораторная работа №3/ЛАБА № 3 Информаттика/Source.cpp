#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale>
#include <malloc.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	const int m = 3, n = 3;
	const int m1 = 4, n1 = 4;
	int arr[m][n];
	int arr1[m1][n1];
	printf("КОДИРОВАНИЕ\n");
	printf("Введите сообщение из 9 чисел в двоичной системе счисления, цифры через пробел:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &arr[i][j]);
			arr1[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < m1; i++)
	{
		int s = 0;
		for (int j = 0; j < n; j++)
		{
			s += arr1[i][j];
		}
		arr1[i][n1 - 1] = s % 2;
	}
	for (int j = 0; j < n1; j++)
	{
		int s = 0;
		for (int i = 0; i < m; i++)
		{
			s += arr1[i][j];
		}
		arr1[m1 - 1][j] = s % 2;
	}
	arr1[m1 - 1][n1 - 1] = 2;
	printf("Матрица:\n");
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{

			if (arr1[i][j] != 2)
			{
				printf("%d", arr1[i][j]);
			}
		}
		printf("\n");
	}
	printf("Закодированное сообщение: ");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", arr1[i][j]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		printf("%d", arr1[i][n1 - 1]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr1[m1 - 1][i]);
	}
	printf("\n\n");
	printf("ДЕКОДИРОВАНИЕ\n");
	int darr[5][3];
	int arr2[m1][n1];
	int str[4] = { 9,9,9,9 };
	int st[4] = { 9,9,9,9 };
	int k = 0;
	int l = 0;
	printf("Введите закодированное сообщение:\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf_s("%d", &darr[i][j]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr2[i][j] = darr[i][j];
		}
	}
	arr2[0][n1 - 1] = darr[3][0];
	arr2[1][n1 - 1] = darr[3][1];
	arr2[2][n1 - 1] = darr[3][2];
	arr2[m1 - 1][0] = darr[4][0];
	arr2[m1 - 1][1] = darr[4][1];
	arr2[m1 - 1][2] = darr[4][2];
	arr2[m1 - 1][n1 - 1] = 2;
	printf("Матрица:\n");
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			if (arr2[i][j] != 2)
			{
				printf("%d", arr2[i][j]);
			}
		}
		printf("\n");
	}
	int s;
	for (int i = 0; i < m1 - 1; i++)
	{
		s = 0;
		for (int j = 0; j < n1; j++)
		{
			s += arr2[i][j];
		}
		if (s % 2 != 0)
		{
			str[k] = i;
			printf("%d ошибка в строке %d\n", k + 1, str[k] + 1);
			k++;
		}
	}
	int t;
	for (int j = 0; j < n1 - 1; j++)
	{
		t = 0;
		for (int i = 0; i < m1; i++)
		{
			t += arr2[i][j];
		}
		if (t % 2 != 0)
		{
			st[l] = j;
			printf("%d ошибка в столбце %d\n", l + 1, st[l] + 1);
			l++;
		}
	}
	if (k > 0 && l == 0)
	{
		printf("ошибка в бите % d\n", str[k] + 9);
	}
	else if (l > 0 && k == 0) {
		printf("ошибка в бите % d\n", st[l] + 14);
	}
	if (k > 0 && l > 0)
	{
		int cm, cn;
		for (int i = 0; i < k; i++)
		{
			cm = str[i];
			cn = st[i];
			if (arr2[cm][cn] == 1)
			{
				arr2[cm][cn] = 0;
			}
			else {
				arr2[cm][cn] = 1;
			}
		}
		printf("Исправленный декодированный код:\n");
	}
	else if (k == 0) {
		printf("Сообщение передано без ошибок\n");
		printf("Декодированный код: ");
	}
	for (int i = 0; i < m1 - 1; i++)
	{
		for (int j = 0; j < n1 - 1; j++)
		{
			printf("%d", arr2[i][j]);
		}
	}
}