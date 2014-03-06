#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_HEIGHT  50+10
#define MAX_WIDTH   100+10
#define MAX_DICES   10
#define MAX_DIR      4

char pixel[MAX_HEIGHT][MAX_WIDTH];
int  visit[MAX_HEIGHT][MAX_WIDTH];
int  dice_dots[MAX_DICES];
/* 上，下，左，右 */
int  dir_y[MAX_DIR] = {0,  0, -1, 1,};
int  dir_x[MAX_DIR] = {-1, 1,  0, 0,};

int Count(int x, int y);
void Swap(int *a, int *b);

int main(int argc, char *argv[])
{
	freopen("test_input.txt", "r", stdin);
    int i, j, w, h, dice, cnt = 0;

    while(scanf("%d%d\n", &w, &h) == 2){
        if (w == 0 && h == 0) 
            break;
        memset(dice_dots, 0, sizeof(dice_dots));
        memset(visit, 0, sizeof(visit));
        memset(pixel, 0, sizeof(pixel));
        for (i = 1; i <= h; ++i){
            for(j = 1; j <= w; ++j){
                  pixel[i][j] = getchar();
            }
            getchar();  /* 回车 */
        }
        
        for (i = 1, dice = 0; i <= h; ++i){
            for (j = 1; j <= w; ++j){
                if (pixel[i][j] == 'X' && visit[i][j] == 0){
                   dice_dots[dice++] = Count(i,j);
                }
            }
        }
        printf("Throw %d\n", ++cnt); 
        /* 冒泡排序 , 从小到大排列*/
        for (i = dice-1; i >= 0; --i){
            for (j = 0; j < i; ++j){
                if (dice_dots[j] > dice_dots[j+1])
                    Swap(&dice_dots[j], &dice_dots[j+1]);
            }
        }

        printf("%d", dice_dots[0]);
        for (i = 1; i < dice; ++i)
            printf(" %d", dice_dots[i]);
        printf("\n\n");
    }

    return 0;
}

void Swap(int *a, int *b)
{
     int c;
     c = *a;
     *a = *b;
     *b = c;
}

void Dfs(int x, int y)
{
    int dir;
    if (pixel[x][y] != 'X' || visit[x][y] != 0)
        return;  
    
    visit[x][y] = 1;
    for (dir = 0; dir < MAX_DIR; ++dir)
        Dfs(x+dir_x[dir], y+dir_y[dir]);
}

int Count(int x, int y)
{
	
    int dir, cnt = 0, _x, _y;
    if ((pixel[x][y] != '*' && pixel[x][y] != 'X') ||
         visit[x][y] != 0)
       return 0;  
    
    visit[x][y] = 1;
    
    if (pixel[x][y] == 'X'){ 
        cnt++;
        for (dir = 0; dir < MAX_DIR; ++dir)
            Dfs(x+dir_x[dir], y+dir_y[dir]);
    }
    for (dir = 0; dir < MAX_DIR; ++dir)
       cnt += Count(x+dir_x[dir], y+dir_y[dir]);
    
    return cnt;
}
