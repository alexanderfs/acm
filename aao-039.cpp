/*******************************************************************
 * Copyright (C) Alex AN
 *               
 * File Name   : 
 * Author      : Alex AN
 * Create      : 
 * Mail        : alexbupt@gmail.com
 * Blog        : http://blog.csdn.net/alexbupt
 *               
 * Description : 计算二叉树的深度。
 扩展案例：判断一个二叉树是否为平衡二叉树：左右子树高度差在1以内即可定义
 为平衡。 基本思想是：先判断左右子树是否为平衡，如果是则计算以当前节点为
 根的子树是否平衡。这时就需要左右子树的深度数据。可以在参数中加一个引用
 来获取此值。 代码在下面 
 *               
 ******************************************************************/

#include <cstdio>
#include <cstdlib>

using namespace std;

int nodelist[100005];
int lclist[100005];
int rclist[100005];
int n;

bool isbalance(int idx, int &depth) {
	if(idx == -1) {
		return true;
	}
	int ld = 0;
	int rd = 0;
	if(isbalance(lc[idx], ld) && isbalance(rc[idx], rd)) {
		int diff = ld - rd;
		if(diff >= -1 && diff <= 1) {
			depth = (ld > rd ? ld : rd) + 1;
			return true;
		}
	}
	return false;
}

int dfs(int idx) {
	if(idx == -1) {
		return 0;
	}
	int depth = dfs(lclist[idx]) + 1;
	int tmp = dfs(rclist[idx]) + 1;
	depth = tmp > depth ? tmp : depth;
	return depth;
}

int main() {
	freopen("test_input.txt", "r", stdin);
	while(1 == scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d %d", &lclist[i], &rclist[i]);
		}
		printf("%d\n", dfs(1));
	}
	
	return 0;
}