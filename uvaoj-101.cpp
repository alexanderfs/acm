#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pileList[26][26];

void findOP(int *base, int *offset, int op)
{
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			if(pileList[i][j] == op) {
				*base = i;
				*offset = j;
				return;
			} else if(pileList[i][j] == -1) {
				break;
			}
		}
	}
}

void movePile(const char *cmd1, const char *cmd2, const int op1, const int op2)
{
	if(op1 == op2) {
		return;
	}
	int base1 = 0;
	int offset1 = 0;
	findOP(&base1, &offset1, op1);
	int base2 = 0;
	int offset2 = 0;
	findOP(&base2, &offset2, op2);
	if(base1 == base2) {
		return;
	}
	int cmdType = -1;
	if(!strcmp("move", cmd1)) {
		if(!strcmp("onto", cmd2)) {
			cmdType = 1;
		} else if(!strcmp("over", cmd2)) {
			cmdType = 2;
		}
	} else if(!strcmp("pile", cmd1)) {
		if(!strcmp("onto", cmd2)) {
			cmdType = 3;
		} else if(!strcmp("over", cmd2)) {
			cmdType = 4;
		}
	}
	
	switch(cmdType) {
	case 1: {
		while(offset1 < 24 && pileList[base1][offset1] != -1) {
			pileList[base1][offset1] = pileList[base1][offset1 + 1];
			offset1++;
		}
		int i = offset2;
		while(i < 25 && pileList[base2][i] != -1) {
			i++;
		}
		while(i > offset2 + 1) {
			pileList[base2][i] = pileList[base2][i - 1];
			i--;
		}
		pileList[base2][i] = op1;
	}
	break;
	case 2: {
		while(offset1 < 24 && pileList[base1][offset1] != -1) {
			pileList[base1][offset1] = pileList[base1][offset1 + 1];
			offset1++;
		}
		int i = offset2;
		while(i < 25 && pileList[base2][i] != -1) {
			i++;
		}
		pileList[base2][i] = op1;
	}
	break;
	case 3: {
		int i = offset1;
		while(pileList[base1][i] != -1) {
			i++;
		}
		i = i - offset1;
		
		int j = offset2;
		while(pileList[base2][j] != -1) {
			j++;
		}
		j--;
		while(j > offset2 + 1) {
			pileList[base2][j + i] = pileList[base2][j];
			j--;
		}
		for(int k = 0; k < i; k++) {
			pileList[base2][offset2 + 1 + k] = pileList[base1][offset1 + k];
			pileList[base1][offset1 + k] = -1;
		}
	}
	break;
	case 4: {
		int j = offset2;
		while(pileList[base2][j] != -1) {
			j++;
		}
		while(pileList[base1][offset1] != -1) {
			pileList[base2][j] = pileList[base1][offset1];
			pileList[base1][offset1] = -1;
			j++;
			offset1++;
		}	
	}
	break;	
	}
}

void print_piles(int len)
{
	for(int i = 0; i < len; i++) {
		printf("%d:", i);
		for(int j = 0; j < len && pileList[i][j] != -1; j++) {
			printf(" %d", pileList[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	freopen("test_input.txt", "r", stdin);
	freopen("test_output.txt", "w", stdout);
	int len;
	scanf("%d\n", &len);
	for(int i = 0; i < 25; i++) {
		for(int j = 0; j < 25; j++) {
			pileList[i][j] = -1;
		}
	}
	for(int i = 0; i < len; i++) {
		pileList[i][0] = i;
	}
	char cmd[50];
	fgets(cmd, 50, stdin);
	//print_piles(len);
	while(NULL == strstr(cmd, "quit")) {
		char cmd1[5];
		char cmd2[5];
		int op1, op2;
		sscanf(cmd, "%s %d %s %d\n", cmd1, &op1, cmd2, &op2);
		movePile(cmd1, cmd2, op1, op2);
		//print_piles(len);
		fgets(cmd, 50, stdin);
	}
	print_piles(len);
	
	return 0;
}