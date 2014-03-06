#include <stdio.h>

int n = 10;
int a[] = {
	10, 9, 18, 7, 66, 5, 49, 3, 2, 1
};

void quickSort(int left, int right)
{
	printf("%d, %d: ", left, right);
	if(left < right) {
		int store = left;
		for(int i = left; i <= right; i++) {
			if(a[i] < a[right]) {
				int tmp = a[store];
				a[store] = a[i];
				a[i] = tmp;
				store++;
			}
		}
		int tmp = a[store];
		a[store] = a[right];
		a[right] = tmp;
		for(int i = left; i <= right; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		quickSort(left, store - 1);
		quickSort(store + 1, right);
	} else {
		printf("\n");
	}
}

int main()
{
	quickSort(0, n - 1);
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}