#include <stdio.h>

int main(void){
    int arr[10]={};
    int i,max,maxNum;

    for(i=0; i<9; i++){
        scanf("%d",&arr[i]);
        if(arr[i]>=100) printf("100보다 작은 자연수를 입력해주세요\n");
    }
  
    max = arr[0];
    for(i=1;i<9;i++){
        if(max<arr[i]){
            max = arr[i];
            maxNum = i+1;
        }
    }

    printf("%d\n",max);
    printf("%d\n",maxNum);

    return 0;
}
