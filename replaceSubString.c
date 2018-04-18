//替换一个字符串中的某一段指定子串为另一段子串

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int replaceSubStr(char *src, char **dst, char *sub, char *new_sub) {
	if (!src && !dst && !sub && !new_sub) {
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}
	char *p = src;
	char *q = p;
	char *temp = malloc(4096);
	if (!temp) {
		fprintf(stderr, "malloc error\n");
		return -1;
	}
	memset(temp, 0, 4096);
	int len_new_sub = strlen(new_sub);
	while ((p = strstr(p, sub)) != NULL) {
		strncat(temp, q, p - q);
		strncat(temp, new_sub, len_new_sub);
		p += strlen(sub);
		q = p;
		if (*p == '\0') //src末尾就是sub
			break;
	}
	if (*q != '\0') { //src末尾不是sub
		int len = src + strlen(src) - q;
		strncat(temp, q, len);
	}
	*dst = temp;
	return 0;
}

int main() {
	char src[] = "abcd11111abcd22222abcdqqqqqabcd   ";
	char *dst = NULL;
	char sub[] = "abc";
	char *new_sub = "dcba";
	int result = replaceSubStr(src, &dst, sub, new_sub);
	if (result < 0) {
		fprintf(stderr, "call of replaceSubStr error\n");
	}
	printf("dst = %s\n", dst);

	return 0;
}
