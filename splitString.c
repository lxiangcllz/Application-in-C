//把一段长字符串按照指定分隔符分割成若干个子串

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int splitString(char *src, char ch, char dst[10][30], int *num) { //用二维数组传出结果
	if (!src && !dst && !num) {
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}
	char *p = src;
	char *q = p;
	int temp_num = 0;
	while ((p = strchr(p, ch)) != NULL) {
		strncat(dst[temp_num], q, p - q);
		p++;
		q = p;
		temp_num++;
		if (*p == '\0') {
			break;
		}
	}
	if (*q != '\0') {
		int len = src + strlen(src) - q;
		strncat(dst[temp_num], q, len);
		temp_num++;
	}
	*num = temp_num;

	return 0;
}

int splitString2(char *src, char ch, char ***dst, int *num) {
	if (!src && !dst && !num) {
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}
	char **temp = NULL;
	int num_string = 0;
	char *p = src;
	char *q = p;
	while ((p = strchr(p, ch)) != NULL) {
		num_string++;
		p++;
		q = p;
	}
	if (*q != '\0') {
		num_string++;
	}
	printf("-------num_string is :%d\n", num_string);//6
	temp = (char **)malloc(sizeof(char *)*num_string);
	if (!temp) {
		fprintf(stderr, "malloc error\n");
		return -1;
	}
	//memset(temp, 0, sizeof(char *)*num_string);//清空各个字符串指针
	p = src;
	q = p;
	int num_temp = 0;
	while ((p = strchr(p, ch)) != NULL) {
		int len_temp = p - q;
		temp[num_temp] = (char *)malloc(len_temp + 1);
		if (!temp[num_temp]) {
			fprintf(stderr, "malloc error\n");
			return -1;
		}
		memset(temp[num_temp], 0, len_temp + 1);//清空每个指针指向的堆内存
		strncat(temp[num_temp], q, len_temp);
		p++;
		q = p;
		num_temp++;
		if (*p == '\0') {
			break;
		}
	}
	if (*q != '\0') {
		int len_end = src + strlen(src) - q;
		strncat(temp[num_temp], q, len_end + 1);
		num_temp++;
	}
	*num = num_temp;
	*dst = temp;
	return 0;
}

int free_mem(char ***dst, int num) {
	if (!dst) {
		fprintf(stderr, "Invalid argument\n");
		return -1;
	}
	char **temp = *dst;
	if (!temp) {
		return 0;
	}
	for (int i = 0; i < num; i++) {
		free(temp[i]);
		temp[i] = NULL;
	}
	free(*dst);
	*dst = NULL;
	return 0;
}

int main() {
	char *src = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char ch = ',';
	//char dst[10][30] = { 0 };//在栈区开辟内存存储分隔开的各个字符串
	char **dst = NULL;//在堆区开辟内存存储各个子字符串
	int cnt = 0;

	int result1 = splitString2(src, ch, &dst, &cnt);
	if (result1 < 0) {
		fprintf(stderr, "splitString error\n");
	}
	printf("Number of substring in [%s] is: %d\n", src, cnt);
	for (int i = 0; i < cnt; i++) {
		printf("dst[%d] = %s\n", i, dst[i]);
	}
	int result2 = free_mem(&dst, cnt);
	if (result2 < 0) {
		fprintf(stderr, "free error\n");
	}
	return 0;
}
