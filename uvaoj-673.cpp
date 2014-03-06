#include <stdio.h>
#include <string.h>

int main()
{
	freopen("test_input.txt", "r", stdin);
	int count;
	scanf("%d", &count);
	getchar();
	char buf[130];
	char stack[130];
	int top = 0;
	while(count--) {
		/*char c;
		int k = 0;
		while(EOF != (c = getchar()) && '\n' != c) {
			buf[k++] = c;
		}
		buf[k] = '\0';*/
		//cin>>buf;
		memset(buf, 0, sizeof(buf));
		fgets(buf, 129, stdin);
		bool isValid = true;
		top = 0;
		for(int i = 0; isValid && buf[i] != '\0' && buf[i] != '\n'; i++) {
			if(buf[i] == '(' || buf[i] == '[') {
				stack[top++] = buf[i];
			} else if(buf[i] == ')') {
				if(top > 0 && stack[top - 1] == '(') {
					top--;
				} else {
					isValid = false;
				}
			} else if(buf[i] == ']') {
				if(top > 0 &&stack[top - 1] == '[') {
					top--;
				} else {
					isValid = false;
				}
			}
		}
		if(isValid && top == 0) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	
	return 0;
}