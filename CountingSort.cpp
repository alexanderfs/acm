#include <stdio.h>

int n = 10;
int a[] = {
	3, 0, 2, 0, 0, 2, 2, 0, 1, 0
};

void countSort()
{
	int b[4] = {
		0, 0, 0, 0
	};
	for(int i = 0; i < n; i++) {
		b[a[i]]++;
	}
	for(int i = 0, j = 0; i < 4; i++) {
		while(b[i]) {
			a[j++] = i;
			b[i]--;
		}
	}
}

int main()
{
	countSort();
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}