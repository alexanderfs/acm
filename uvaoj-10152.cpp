/*0.038s*/

#include<cstdio>
#include<cstring>

char origin[210][100], require[210][100];

int main()
{
	freopen("test_input.txt", "r", stdin);
	int cas, i, j, n;
	scanf("%d\n", &cas);
	while (cas--)
	{
		scanf("%d\n", &n);
		for (i = 0; i < n; i++) gets(origin[i]);
		for (i = 0; i < n; i++) gets(require[i]);
		for (i = n - 1, j = n - 1; i >= 0 && j >= 0;)
		{
			if (strcmp(origin[i], require[j]) == 0)
				i--, j--;
			else
				i--;
		}
		while (j >= 0) puts(require[j--]);
		putchar(10);
	}
	return 0;
}
