#include <stdio.h>

void 
add (int a, int b){
    
    printf("%d\n", a + b);
}

void
muti (int a, int b){
    printf("%d", a*b);
}

int
main (){
    void (*fp)(int, int);

    fp = add;
    fp(2,4);
    fp = muti;
    fp(2,4);

 return 0;
}
