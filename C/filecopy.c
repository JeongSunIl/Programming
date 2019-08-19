#include <stdio.h> 

int
main ()  //정의를 할떈, 띄우고, 부를 떄는 붙인다. search를 쉽게하기 위해
{
	int c ; // EOF or error or int value 를 어떻게 표현할 것인가? -> char가 아닌 int 

	c = getchar() ; // standard input(Stdin-keyboard)
	while (c != EOF) {
		putchar(c) ; // 'c' is integer, stdout-console
		c = getchar() ;
	}
}
