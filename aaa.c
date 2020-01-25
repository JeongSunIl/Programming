#include <stdio.h>

int
main (){

    int n;
    int mod;
    int ch = 'a';

    while(1){
        n = 0;
        mod = 0;
        ch = getchar();
        if( ch == 'q' )
            break;
    scanf("%d %d", &n, &mod);

    printf("%d mod %d = %d", n, mod, (n%mod));
    }

    return 0;
}
