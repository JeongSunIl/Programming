#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024;

int 
main (int argc, char** argv){
    int sock;
    int str_len;
    int recv_len;
    int recv_cnt;
    int count=0,i;
    int operand[BUF_SIZE];
    char operator;
    struct sockaddr_in addr;
    
    char message[1024];

    sock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(atoi(argv[1]));

    connect(sock, (struct sockaddr*)&addr, sizeof(addr));
   
    printf("Operand count: ");
    scanf("%d",&count);
    for(i=0;i<count;i++){
        printf("Operand %d: ",i+1);
        scanf("%d",operand);
        str_len = write(sock, &operator, sizeof(int));
        

        message[recv_len] = 0x0;
        printf("Message from server : %s \n", message);
        }
    close(sock);
    return 0;
}
