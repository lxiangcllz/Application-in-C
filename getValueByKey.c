//输入一串字符，包括key和value
//通过key得到对应的value字符串

#include <stdio.h>
#include <string.h>
//#include <ctype.h>

//从一个两端有可能包含若干空格的字符串src中去掉两端的空格放入dst中，并返回字符的个数
int getStringSkipSpace(char *src, char *dst) {
	if ((src == NULL) || (dst == NULL)) { //if(!src && !dst)
		fprintf(stderr, "arguments of getStringSkipSpace is wrong");
		return -1;
	}
	char *p = src;
	char *q = src + strlen(src) - 1;
	int cnt = 0;
	while (*p == ' ' && *p != '\0') p++;
	//while(isspace(p) && *p != '\0') p++;
	while (*q == ' ' && q >= p) q--;
	//while (isspace(q) && q >= p) q--;
	cnt = q - p + 1;
	strncat(dst, p, cnt);

	return cnt;
}

//通过key得到对应的value字符串
//第一个参数存原始字符串,第二个参数存待查找的key
//第三个参数存找到的value，第四个存找到的value的长度
int getValueByKey(char *keyValueBuf, char *keyBuf, char *valueBuf, int *valueBufLen) {
	//if(!keyValueBuf && !keyBuf && !valueBuf && !valueBufLen)
	if ((keyValueBuf == NULL) || (keyBuf == NULL) || (valueBuf == NULL) || (valueBufLen == NULL)) {
		fprintf(stderr, "arguments of getValueByKey is wrong\n");
		return -1;
	}
	char *p = keyValueBuf;
	//char *k = keyBuf;
	//char *v = valueBuf;
	//int *len = valueBufLen;

	p = strstr(p, keyBuf);
	if (p == NULL) {
		fprintf("%s Not found\n", keyBuf);
		return -1;
	}
	p += strlen(keyBuf);
	
	p = strstr(p, "=");
	if (p == NULL) {
		fprintf(stderr, "%s not found\n", "=");
		return -1;
	}
	p += strlen("=");

	*valueBufLen = getStringSkipSpace(p, valueBuf);

	return 0;
}

int main() {
	char keyvaluestr[] = "key1 = value1and1341   ";
	char *key = "key1";
	char *valuebuf[128] = { 0 };
	int len = 0;

	int result = getValueByKey(keyvaluestr, key, valuebuf, &len);
	if (result < 0) {
		fprintf(stderr, "getValueByKey goes wrong\n");
		return 0;
	}
	printf("The value of [%s] in [%s] is : [%s]:(%d)\n", key, keyvaluestr, valuebuf, len);
	return 0;
}
