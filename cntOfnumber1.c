#include <stdio.h>

//求参数x的二进制表示中的1的个数
int numOf1(int x) {
	int cnt = 0;
	while(x) {
		cnt++;
		x = x & (x-1);
	}
	return cnt;
}

//求参数x的二进制表示中的0的个数（还有问题）
int numOf0(int x) {
	int cnt = 0;
	while(x+1) {
		cnt++;
		x = x | (x+1);
	}
	return cnt;
}

int main() {
	int num;
	while(scanf("%d", &num)) {
		printf("%d\n", numOf1(num));
		printf("%d\n", numOf0(num));
	}
	return 0;
}
