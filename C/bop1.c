#include <stdio.h>


unsigned int getbits(unsigned int x, int p, int n) ;
unsigned int setbit(unsigned int x, int b, int v);

int
main ()
{
	unsigned int n = 0xabcd ;
	printf("%d\n", n) ;

	printf("%x\n", n & 0xff00); // &:bit AND operator, mask

	printf("%x\n", n & ~0xf) ; // type inference --> ~0xf(type없음)가 n과 같은 type이라는 것으로 이해. (이해가 잘 못되면, type error) ~(negation)을 통해 mask

	printf("%x\n", n << 4) ; // << : 1bit씩 왼쪽으로 감. >>

	printf("%x\n", getbits(n, 4, 8)) ;
    printf("%x\n", setbit(n, 5, 0));
    printf("%x\n", setbit(n, 5,1));
}

unsigned int getbits(unsigned int x, int p, int n) 
{
	return (x >> p ) & ~(~0 << n) ; //
}

unsigned int setbit(unsigned int x, int b, int v)  //1->32 , v: 0 or 1
{
	return v ? (x | (0x1 << (b-1)))  : (x  & ~(0x1 << (b-1)));  
}
