//检查一个程序的花括号对 

#include <stdio.h>
#include <stdlib.h>

int main() {
	int ch;
	int braces;
	
	braces = 0;
	
	while((ch = getchar()) != EOF) {
		if(ch == '{') 
			braces++;
		
		if(ch == '}')
			if(braces == 0) 
				printf("Extra closing brace!\n");
			else 
				braces--;
	}
	
	if(braces > 0)
		printf("%d unmatched opening brace(s)!\n", braces);
	
	return EXIT_SUCCESS;
}
