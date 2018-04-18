//10进制数转为2进制数

void decimal2binary(int n) {
	if (n < 2)
		printf("%d", n);
	else{
		decimal2binary(n / 2);
		printf("%d", n % 2);
	}
	return;
}
