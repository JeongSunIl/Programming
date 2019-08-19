#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 1024

void executor (char* ptr, int value[][3]);
int isNum (char* ptr);
int checker(char* a);
int address[30];
int count=0;
char* library[8] = {"READ","MOD","JUMP","ADD","LESS","WRITE","TERM","EQ"};
int end=0;

int
main (){
    char line[MAX_LEN];
    int value[30][3]={};
    char** inst;
    char* ptr;
    int ch, i, j;
    int state=0;

    inst = (char**)malloc(sizeof(char*)*50);
    for(i=0; i<100; i++) inst[i] = (char*)malloc(sizeof(char)*50);
    

    while(fgets(line, MAX_LEN, stdin)){
        ptr = strtok(line," \n[]");
        i = 0;
        while(ptr!=NULL){
            
          if((checker(ptr)) && state==0){  
              strcpy(inst[count],ptr);
              state = 1;
          }
          else if(state==1 && isNum(ptr)) {
              value[count][i]=atoi(ptr);
              i += 1;
          }
          else if(state==0 && isNum(ptr)) address[count]=atoi(ptr);
           
         ptr = strtok(NULL," \n[]");
        }
        count += 1;
        state = 0;
       }
    
    count = 0;

   /* while(count<30){
        if(end==1) exit(0);
      printf("count:%d  end:%d\n",count, end);
      printf("count:%d inst:%s\n",count, inst[count]);
      executor(inst[count],value);
      count += 1;
    }*/

      for(i=0;i<30;i++){
          executor(inst[count],value);
          count += 1;
      }
 }

int checker(char *a){
    int i, result=0;

  for(i=0; i<8; i++){
          if(strcmp(library[i],a) == 0){ 
              result = 1;
              break;
          }
  }

  return result;

}


void 
executor (char* ptr, int value[][3]){
    int i=0;
    int num;
    char str[30] = {};
    //char* library[8] = {"READ","MOD","JUMP","ADD","LESS","WRITE","TERM","EQ"};
    for(i=0; i<8; i++){
       printf("%s ",ptr);
        if(strcmp(library[i],ptr) == 0) {
            printf("====%d====",i);
            switch(i){
               case 0 :address[value[count][0]] = 7; 
                       printf("입력받았다고? %d", address[value[count][0]]);
                   break;
               case 1 :  address[value[count][0]] = address[value[count][1]] % address[value[count][2]]; 
                   break;
               case 2 : if(address[value[count][1]] == 1) count = value[count][0]-1;
                   break;
               case 3: address[value[count][0]] = address[value[count][1]] + address[value[count][2]];
                  break;
               case 4 :  address[value[count][0]] = address[value[count][1]] <  address[value[count][2]];
                  break;
               case 5 : printf("result: %d\n", address[value[count][0]]);
                  break;
               case 6 : end=1; printf("end=%d",end);
                  break;
               case 7 : address[value[count][0]] = (address[value[count][1]] ==  address[value[count][2]]);
                  break;

            }
            break;
        }
       
    }
   
}

int isNum (char* ptr){
    int i=0;
    int result = 0;
    for(i=0; i< ptr[i]!='\0';i++){
       result = isdigit(ptr[i]);
       if(result == 1) break;
    }

    return result;
}
