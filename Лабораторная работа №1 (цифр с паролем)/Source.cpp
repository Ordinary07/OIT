#include <stdio.h>
#include <string.h>

int main()
{
	char a[100], b[100];
	char pass[26];
	char m[2][26];
	printf("Enter text: ");
	gets_s(a);

	printf("Enter password: ");
	gets_s(pass);
	int i;
	for (i = 0; i < 26; i++)
	{
		m[0][i] = 'a' + i;
		m[1][i] = '\0';
	}
	int j = 0;
	i = 0;
	while (pass[i] != '\0')
	{
		m[1][i] = pass[i];
		i++;
	}
	while (i < 26)
	{
		if (strchr(pass, m[0][j]) != NULL)
			j++;
		else
		{
			m[1][i] = m[0][j];
			i++;
			j++;
		}
	}
	for (int i = 0; i < 26; i++)
		printf("%c ", m[0][i]);
	printf("\n");
	for (int i = 0; i < 26; i++)
		printf("%c ", m[1][i]);
	printf("\n");
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] >= 97 && a[i] <= 122)
			b[i] = m[1][a[i] - 97];
		else
			b[i] = a[i];
		i++;
	}
	b[i] = '\0';
	puts(b);

	while (a[i] != '\0')
	{
		if (b[i] >= 97 && b[i] <= 122)
			a[i] = m[0][b[i] - 97];
		else
			a[i] = b[i];
		i++;
	}
	a[i] = '\0';
	puts(a);
	getchar();
	return 0;
}
