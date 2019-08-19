#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int 
main (int argc, char** argv){
    int sock;
    int str_len;
    int recv_len;
    int recv_cnt;
    struct sockaddr_in addr;
    
    char message[1024];

    sock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(atoi(argv[1]));

    connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    
    while(1){
        fgets(message,1024, stdin);
        str_len = write(sock,message, strlen(message));
        if(!strcmp(message,"q\n")||!strcmp(message,"Q\n"))
               break;
        
       recv_len = read(sock,message,1023);

      /*  recv_len =0;
        while(recv_len < str_len){
          recv_cnt  = read(sock, message, sizeof(message));
          recv_len += recv_cnt;
        }*/
        message[recv_len] = 0x0;
        printf("Message from server : %s \n", message);
    }
    close(sock);
    return 0;
}
