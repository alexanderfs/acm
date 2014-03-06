#include <stdio.h>

char graph[51][51];
char vGraph[50][50];
int diceCount = 0;
int w, h;
int offsetX[4] = {
	-1, 0, 1, 0
};
int offsetY[4] = {
	0, 1, 0, -1
};
int diceValue[100] = {0};

bool checkValidX(int x)
{
	if(x >= 0 && x < h)	return true;
	else return false;
}

bool checkValidY(int y)
{
	if(y >= 0 && y < w)	return true;
	else return false;
}


int stack[100] = {0};
int top = 0;

void dfs2(int x, int y)
{
	vGraph[x][y] = 1;//visiting
	for(int i = 0; i < 4; i++) {
		int nx = x + offsetX[i];
		int ny = y + offsetY[i];
		if(checkValidX(nx) && checkValidY(ny) &&
			graph[nx][ny] != '.' && vGraph[nx][ny] == 0) {
				if(graph[nx][ny] == 'X') {
					dfs2(nx, ny);
				} else {
					stack[top++] = nx;
					stack[top++] = ny;
				}
		}
	}
	vGraph[x][y] = 2;
}

void dfs1(int x, int y)
{
	vGraph[x][y] = 1;//visiting
	for(int i = 0; i < 4; i++) {
		int nx = x + offsetX[i];
		int ny = y + offsetY[i];
		if(checkValidX(nx) && checkValidY(ny) &&
			graph[nx][ny] != '.' && vGraph[nx][ny] == 0) {
				if(graph[nx][ny] == 'X') {
					diceValue[diceCount - 1]++;
					dfs2(nx, ny);
					if(top > 0) {
						while(top > 0) {
							if(vGraph[stack[top - 2]][stack[top - 1]] == 0) {
								dfs1(stack[top - 2], stack[top - 1]);
							}
							top -= 2;
						}
					}
				} else {
					dfs1(nx, ny);
				}
		}
	}
	vGraph[x][y] = 2;
}

int main()
{
	freopen("test_input.txt", "r", stdin);
//	freopen("test_output.txt", "w", stdout);

	int count = 0;
	
	while(true) {
		scanf("%d %d\n", &w, &h);
		if(w == 0 && h == 0) {
			break;
		}
		diceCount = 0;
		for(int i = 0; i < h; i++) {
			scanf("%s", graph[i]);
		}
		
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				if(graph[i][j] != '.' && vGraph[i][j] == 0) {
					diceCount++;
					if(graph[i][j] == '*') {
						dfs1(i, j);
					} else {
						diceValue[diceCount - 1]++;
						dfs2(i, j);
						if(top > 0) {
						while(top > 0) {
							if(vGraph[stack[top - 2]][stack[top - 1]] == 0) {
								dfs1(stack[top - 2], stack[top - 1]);
							}
							top -= 2;
						}
					}
					}
				}
			}
		}
		
		
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				vGraph[i][j] = 0;
			}
		}
		
		for(int i = 1; i < diceCount; i++) {
			int tmp = diceValue[i];
			int j = i - 1;
			while(j >= 0 && diceValue[j] > tmp) {
				diceValue[j + 1] = diceValue[j];
				j--;
			}
			diceValue[j + 1] = tmp;
		}
		printf("Throw %d\n", ++count);
		for(int i = 0; i < diceCount; i++) {
			if(i != diceCount - 1) {
				printf("%d ", diceValue[i]);
				diceValue[i] = 0;
			}
			else {
				printf("%d\n", diceValue[i]);
				diceValue[i] = 0;
			}
		}
		printf("\n");
	}
	
	
	return 0;
}
