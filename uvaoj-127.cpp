#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ITEM_COUNT  52

char valid[ITEM_COUNT];
typedef struct card {
	char rank;
	char suit;
} CARD;
int top[ITEM_COUNT];
CARD stackList[ITEM_COUNT][ITEM_COUNT];

bool checkMatch(int a, int b) {
	if (stackList[a][top[a] - 1].rank ==
		stackList[b][top[b] - 1].rank) {
		return true;
	}
	if (stackList[a][top[a] - 1].suit ==
		stackList[b][top[b] - 1].suit) {
		return true;
	}
	return false;
}

int findTo(int from)
{
	int count = 0;
	int to = from - 1;
	while (to >= 0) {
		if (valid[to] == 1) {
			count++;
			if (count == 3 && checkMatch(to, from)) {
				return to;
			}
		}
		to--;
	}
	if (to < 0) {
		to = from - 1;
		while (to >= 0) {
			if (valid[to] == 1 && checkMatch(to, from)) {
				return to;
			}
			to--;
		}
	}
	return -1;
}

void proceedMove(int from)
{
	int pre = findTo(from);
	if (pre == -1) {
		return;
	}
	else {
		top[from]--;
		stackList[pre][top[pre]].rank = stackList[from][top[from]].rank;
		stackList[pre][top[pre]].suit = stackList[from][top[from]].suit;
		top[pre]++;
		if (top[from] == 0) {
			valid[from] = 0;
		}
		proceedMove(pre);
		pre++;
		while (pre <= from) {
			if (valid[pre]) {
				proceedMove(pre);
			}
			pre++;
		}
	}
}

void print_curr()
{
	for (int i = 0; i < ITEM_COUNT; i++) {
		if (valid[i])
			printf("%c%c ", stackList[i][top[i] - 1].rank, stackList[i][top[i] - 1].suit);
		else
			printf("** ");
	}
	printf("\n");
}

int main()
{
	freopen("test_input.txt", "r", stdin);
	freopen("test_output.txt", "w", stdout);
	while (1) {
		memset(valid, 1, sizeof(char)* ITEM_COUNT);
		memset(top, 0, sizeof(int)* ITEM_COUNT);
		for (int i = 0; i < ITEM_COUNT; i++) {
			char buf[3];
			scanf("%s", buf);
			if (buf[0] == '#') {
				return 0;
			}
			stackList[i][top[i]].rank = buf[0];
			stackList[i][top[i]].suit = buf[1];
			top[i]++;
		}

		for (int i = 1; i < ITEM_COUNT; i++) {
			proceedMove(i);
			print_curr();
		}

		int validCount = 0;
		for (int i = 0; i < ITEM_COUNT; i++) {
			if (valid[i]) {
				validCount++;
			}
		}
		printf("%d %s remaining:", validCount, validCount == 1 ? "pile" : "piles");
		for (int i = 0; i < ITEM_COUNT; i++) {
			if (valid[i]) {
				printf(" %d", top[i]);
			}
		}
		printf("\n");
	}

	return 0;
}