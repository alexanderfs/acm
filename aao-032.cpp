/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>

using namespace std;

int cali(int i, int n) {
	int j = i + 1;
	int up = 1;
	while(j--) {
		up *= 10;
	}
	int mul = n / up;
	int val = n % up;
	int low = up / 10;
	up = low * 2;
	int re = mul * low;
	if(val >= up) {
		re += low;
	} else if(val >= low && val < up) {
		re += val - low + 1;
	}
	return re;
}

int caln(int n) {
	int val = n;
	int i = 0;
	int sum = 0;
	while(val > 0) {
		sum += cali(i, n);
		val /= 10;
		i++;
	}
	return sum;
}

int main() {
	freopen("test_input.txt", "r", stdin);
	int a, b;
	/*while(1 == scanf("%d", &a)) {
		printf("%d: %d\n", a, caln(a));
	}*/
	while(2 == scanf("%d %d", &a, &b)) {
		if(a > b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
		int suma = caln(a - 1);
		int sumb = caln(b);
		printf("%d\n", sumb - suma);
	}

	return 0;
}