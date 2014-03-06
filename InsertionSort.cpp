#include <stdio.h>

int n = 4;
int a[] = {
	4, 3, 1, 2
};

void sort()
{
	for(int i = 1; i < n; i++) {
		int val = a[i];
		int j = i - 1;
		while(j >= 0 && a[j] > val) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = val;
	}
}

int main()
{
	sort();
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}