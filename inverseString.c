//逆序一个字符串

#include <stdio.h>
#include <string.h>

void inverseString(char *src) { //non-recursive
	char *left = src;
	char *right = src + strlen(src) - 1;
	while (left < right) {
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
	return;
}

void inverseString2(char *src) { //recursive
	//char *p = src + strlen(src) - 1;
	if (*src != '\0') {
		inverseString2(src + 1);
	}
	printf("%c", *src);
}

void inverseString3(char *src, char *dst) { //another recursive version
	if (*src != '\0') {
		inverseString3(src + 1, dst);
	}
	strncat(dst, src, 1);
}

void const_test(const int *a) {
	*((int *)a) = 30;
}

int main() {
	char str[] = "abcdefg";//注意：此处若写成char *str = "abcdefg"; 则会出错，二者有本质区别
	char dst[128] = { 0 };
	inverseString3(str, dst);
	inverseString2(str);
	//printf("inverseString(str) is : %s\n", str);
	printf("inverseString3(str) is : %s\n", dst);
}
