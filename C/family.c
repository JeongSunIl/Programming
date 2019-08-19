#include <stdio.h>
#include <stdlib.h>


void
Ftree(char** parent, char** child, int indent);

//int indent=0;

int
main(){
    char** parent;
    char** child;
    int name;
    int childN;
    int relation;
    int i;
    int j;
    scanf("%d %d",&name,&relation);
    
    parent = (char**)malloc(sizeof(char*)*relation);
    child = (char**)malloc(sizeof(char*)*relation);

    for(i=0;i<relation;i++){
        parent[i] = (char*)malloc(sizeof(char)*10);
        child[i] = (char*)malloc(sizeof(char)*10);
    }

    for(i=0;i<relation;i++){
        scanf("%s %s",parent[i], child[i]);
    }

    for(i=0;i<relation;i++){
        printf("%s %s",parent[i], child[i]);
    }
   
   for(i=0;i<relation;i++){
       for(j=0; j<relation; j++){
           if(strcmp(parent[i],child[j] == 0) break;
                   
         }
        if(j==relation) Ftree(parent,child, indent);
   return 0;

}


void Ftree(char** parent, char** child, int indent){
        
   

}
    


