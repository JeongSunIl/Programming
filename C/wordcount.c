#include <stdio.h>

#define IN	1 //macro - 컴파일러 이전에 해석 : IN --> 1, OUT --> 0
#define OUT	0

int
main () 
{
	int c, state ;
	int nc, nw, nl; // num of char, num of word, num of line;

	nc = (nw = (nl = 0)) ;

	state = OUT ;
	while ((c = getchar()) != EOF) {
		nc += 1 ;

		if (c == '\n')
			nl += 1 ;

		if (c ==(int) ' ' || c == '\n' || c == '\t') { //casting
			state = OUT ; //word의 커서가 word의 밖에 있는 상태
		}
		else if (state == OUT) {
			state = IN ;
			nw += 1 ;
		}
	}

	printf("%d\t%d\t%d\n", nl, nw, nc) ;
}
