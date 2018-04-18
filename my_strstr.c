//实现C库函数：strstr: 查找一个字符串中的某一个子串第一次出现的位置

#include <stdio.h>
#include <string.h>

char *my_strstr(const char* src, const char *dst) {
	if(!src && !dst) {
		fprintf(stderr, "Invalid Argument\n");
		return NULL;
	}
	const char *p = src;
	const char *q = dst;
	unsigned len = src + strlen(src) - p;
	//while(*p != '\0') { 
	while(len >= strlen(dst)) { //若移动到最后母串的剩余长度不够待查子串的长度就提前退出
		if(*p == *q) {
			const char *pindex = p;
			const char *qindex = q;
			while(*pindex == *qindex) {
				pindex++;
				qindex++;
				if(*qindex == '\0') {
					return p;
				}
			}

		}
		p++;
	}
	return NULL;
}

int main() {
	char *s = "abcdefg";
	char *d = "cdef";
	char *p = my_strstr(s, d);
	if(!p) {
		fprintf(stderr, "Not found\n");
	}
	else {
		printf("%s\n", p);
	}

	return 0;
}
