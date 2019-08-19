#include <stdio.h>
#include <ctype.h>

#define IN	1
#define OUT	0

//global variable 은 중요한 값이기에 메모리 공간에 고정값으로 넣어줌. local variable은 언제 쓰일지 모르기에  메모리 공간에 stack에 저장하여 씀.

int
main () 
{
    int state_start_quote = OUT;
    int state_end_quote = OUT;
    int state_back = OUT;
    int state_start_star = OUT;
    int state_double = OUT;
    int state_start_slash = OUT;
    int state_end_star = OUT;
    int state_end_slash = OUT;
    int state_enter = OUT;
    int c;

	
	while ((c = getchar()) != EOF) {
        if(c == '/')
            state_start_slash = IN;
        else if (state_start_slash == IN && c == '*') 
            state_start_star = IN;
        else if (state_start_star == IN && c == '*')
             state_end_star = IN;
        else if (state_end_star == IN && c == '/')
            state_end_slash = IN;
        
        if(c=='/')
            state_start_slash = IN;
        else if(state_start_slash == IN && c == '/')
            state_end_slash = IN;
        else if(state_end_slash == IN && c =='\n')
            state_enter = IN;

        

        if(c=='\"')
            state_start_quote = IN;
        else if(state_start_quote == IN && c == '\\')
            state_start_slash = IN;
        else if(state_start_slash = OUT && c == '\"')
            state_end_quote = IN;



        if(state_end_slash == IN && state_end_star == IN){
            state_start_star = OUT;
            state_start_slash = OUT;
            state_end_star = OUT;
            state_end_slash = OUT;
        }
        else if(state_enter == IN){
            state_start_slash = OUT;
            state_end_slash = OUT;
            state_enter = OUT;
        }
        else if(state_end_quote == IN && state_start_quote == IN){
            state_start_quote = OUT;
            state_start_slash = OUT;
            state_end_quote = OUT;
       }
       else{
           putchar(c);
       }
        
       
       

			
    }

}
