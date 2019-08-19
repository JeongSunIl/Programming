#include <stdio.h>

int
main(){
    int slash_state=0;
    int star_state=0;
    int checker=0;
    int back_state=0;
    int ch;


    for(ch=getchar();ch!=EOF;ch=getchar()){
         if(slash_state == 1 && ch == '*'&&star_state ==0) star_state = 1;
         else if(slash_state == 1 && star_state == 1){
             if(ch=='*') checker = 1;
             if(slash_state == 1 && checker==1){
                 if(ch=='/'){
                     slash_state = 0;
                     star_state = 0;
                     checker =0;
                 }
             }
         }
         else if(slash_state == 2){
             if(ch=='\n'){
                 slash_state = 0;
             }
         }

         else if(ch=='/') slash_state += 1;
         else {
             putchar(ch);
             slash_state = 0;
             star_state = 0;
             checker = 0;
         }
            
    }
}
