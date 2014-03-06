#include <stdio.h>

int n = 10;
int a[] = {
	10, 9, 8, 7, 6, 5, 4, 3, 2, 1
};

void HeapSort(int idx, int max) {
	int left = idx * 2 + 1;
	int right = idx * 2 + 2;
	int largest = idx;
	if(left < max && a[idx] < a[left]) {
		largest = left;
	}
	if(right < max && a[largest] < a[right]) {
		largest = right;
	}
	if(largest != idx) {
		int tmp = a[idx];
		a[idx] = a[largest];
		a[largest] = tmp;
		HeapSort(largest, max);
	}
}

int main()
{
	for(int i = n / 2 - 1; i >= 0; i--) {
		HeapSort(i, n);
	}
	for(int i = n - 1; i > 0; i--) {
		int tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		HeapSort(0, i);
	}
	
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}
