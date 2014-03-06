#include <stdio.h>

char pileList[25][25];
int topIndex[24];
int num;

int getCmdType(const char *a, const char *b)
{
	if(a[0] == 'm' && b[1] == 'n')	return 1;
	else if(a[0] == 'm' && b[1] == 'v') return 2;
	else if(a[0] == 'p' && b[1] == 'n') return 3;
	else if(a[0] == 'p' && b[1] == 'v') return 4;
}

void getOffset(int *base, int *offset, int op)
{
	for(int i = 0; i < num; i++) {
		int top = topIndex[i] - 1;
		while(top >= 0) {
			if(pileList[i][top] == op) {
				*base = i;
				*offset = top;
				return;
			}
			top--;
		}
	}
}

void print_result()
{
	for(int i = 0; i < num; i++) {
		printf("%d:", i);
		for(int j = 0; j < topIndex[i]; j++) {
			printf(" %d", pileList[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	freopen("test_input.txt", "r", stdin);
	for(int i = 0; i < 24; i++) {
		topIndex[i] = 0;
	}
	
	scanf("%d\n", &num);
	for(int i = 0; i < num; i++) {
		pileList[i][topIndex[i]++] = (char) i;
	}
	char cmd[50];
	fgets(cmd, 49, stdin);
	while(cmd[0] != 'q') {
		char cmd1[5];
		char cmd2[5];
		int op1;
		int op2;
		sscanf(cmd, "%s %d %s %d", cmd1, &op1, cmd2, &op2);
		int type = getCmdType(cmd1, cmd2);
		int base1, offset1;
		int base2, offset2;
		getOffset(&base1, &offset1, op1);
		getOffset(&base2, &offset2, op2);
		if(base1 == base2) {
			type = 5;
		}
		int count;
		switch(type) {
			case 1:
				while(offset1 + 1 < topIndex[base1]) {
					int tmp = pileList[base1][--topIndex[base1]];
					pileList[tmp][topIndex[tmp]++] = tmp;
				}
				getOffset(&base2, &offset2, op2);
				while(offset2 + 1 < topIndex[base2]) {
					int tmp = pileList[base2][--topIndex[base2]];
					pileList[tmp][topIndex[tmp]++] = tmp;
				}
				pileList[base2][topIndex[base2]++] = 
					pileList[base1][--topIndex[base1]];
			break;
			case 2:
				while(offset1 + 1 < topIndex[base1]) {
					int tmp = pileList[base1][--topIndex[base1]];
					pileList[tmp][topIndex[tmp]++] = tmp;
				}
				getOffset(&base2, &offset2, op2);
				pileList[base2][topIndex[base2]++] = 
					pileList[base1][--topIndex[base1]];
			break;
			case 3:
				//如果a在b的上面
				while(offset2 + 1 < topIndex[base2]) {
					int tmp = pileList[base2][--topIndex[base2]];
					pileList[tmp][topIndex[tmp]++] = tmp;
				} 
				count = topIndex[base1] - offset1;
				for(int i = 0; i < count; i++) {
					pileList[base2][topIndex[base2]++] = pileList[base1][offset1 + i];
				}
				topIndex[base1] -= count;
			break;
			case 4:
				if(base1 == base2) {
					break;
				}
				count = topIndex[base1] - offset1;
				for(int i = 0; i < count; i++) {
					pileList[base2][topIndex[base2]++] = pileList[base1][offset1 + i];
				}
				topIndex[base1] -= count;
			break;
		}
		
		fgets(cmd, 49, stdin);
	}
	print_result();
	return 0;
}
