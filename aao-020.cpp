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

int mat[1005][1005];
int m, n;
int colspan;
int rowspan;

int main() {
	freopen("test_input.txt", "r", stdin);
	while(2 == scanf("%d %d", &m, &n)) {
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		colspan = n - 1;
		rowspan = m - 1;
		int x = 1;
		int y = 1;
		while(colspan > 0 && rowspan > 0) {
			for(int i = 1; i <= colspan; i++) {
				printf("%d ", mat[x][y]);
				y++;
			}
			for(int i = 1; i <= rowspan; i++) {
				printf("%d ", mat[x][y]);
				x++;
			}
			for(int i = 1; i <= colspan; i++) {
				printf("%d ", mat[x][y]);
				y--;
			}
			for(int i = 1; i <= rowspan; i++) {
				printf("%d ", mat[x][y]);
				x--;
			}
			x++;
			y++;
			colspan -= 2;
			rowspan -= 2;
		}
		if(colspan >= 0 && rowspan >= 0) {
			if(colspan == 0) {
				for(int i = 0; i <= rowspan; i++) {
					printf("%d ", mat[x][y]);
					x++;
				}
			} else {
				for(int i = 0; i <= colspan; i++) {
					printf("%d ", mat[x][y]);
					y++;
				}
			}
		}
		printf("\n");
	}
	return 0;
}