#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

void FindSignBite(double ChisloWithSign) { //������� 1 ��� ��� �����//topish
	if (ChisloWithSign < 0) {
		printf("1");
	}
	else {
		printf("0");
	}
}

int IntPartAndExp(int IntNumber, int arr[], int arr2[])//������� ����� ����� ����� + ����������� ����������
{
	if (IntNumber > 0) {
		int CountZero = 0;
		int CountOne = 0;
		int i = 0;
		int i2 = 0;
		while ((IntNumber != 0))         // ��������� ������ ����� ���� ������� ����� ���� � �������� ���� 1 �������������
		{

			if (IntNumber % 2 == 0)
			{
				arr[i] = 0;
				CountZero += 1;
			}

			else
			{
				arr[i] = 1;

				CountOne += 1;
			}
			IntNumber = IntNumber / 2;
			i++;

		}
		int E = (CountZero + CountOne) - 1;
		int Exp = E + 1023;

		while ((Exp != 0))         // ��������� ������ ����� ���� ������� ����� ���� � �������� ���� 1 �������������
		{

			if (Exp % 2 == 0)
			{
				arr2[i2] = 0;

			}

			else
			{
				arr2[i2] = 1;

			}
			Exp = Exp / 2;
			i2++;
		}
		i2 = i2 - 1;                //�������������� ������, ����� ��������� ��� ������ 
		for (; i2 >= 0; i2--) {
			printf("%d", arr2[i2]);
		}
		printf(" ");

		i = i - 1;                            //�������������� ������, ����� ��������� ��� ������ 
		for (; i >= 13; i--) {
			printf("%d", arr[i]);
		}

		i = i - 1;                            //�������������� ������, ����� ��������� ��� ������ 
		for (; i >= 0; i--) {
			printf("%d", arr[i]);
		}

	}

	return 0;
}


double DoublePart(double x) 
{
	for (int i = 0; i < 39; i++)
	{
		x *= 2;
		int t = x; 
		printf("%d", t);
		x = x - t;
		
	}
	printf("\n");
	return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	printf("����� -14923.23645 �� ���������� ������������� ����������:\n ");
	double ChisloWithSigh = -14923.23645;
	int a = 14923;
	int arr[16];
	int arr2[16];
	double b = 0.23645;

	FindSignBite(ChisloWithSigh);
	printf(" ");

	IntPartAndExp(a, arr, arr2);
	printf(" ");

	DoublePart(b);

	return 0;


}