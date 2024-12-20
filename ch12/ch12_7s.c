#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9000

int main(){
  char buf[256];
  struct sockaddr_in sin, cli;
  int sd, ns, clientlen = sizeof(cli);

  if ((sd = socket(AF_INET, SOCK_STREAM, 0)) ==-1){
    perror("socket");
    exit(1);
  }

  memset((char *)&sin, '\n', sizeof(sin));
  sin.sin_family =AF_INET;
  sin.sin_port = htons(PORTNUM);
  sin.sin_addr.s_addr = inet_addr("192.168.0.145");

  if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))){
    perror("bind");
    exit(1);
  }

  if(listen(sd, 5)){
    perror("listen");
    exit(1);
  }

  if((ns=accept(sd, (struct sockaddr *)&cli, &clientlen)) ==-1){
    perror("accept");
    exit(1);
  }

  sprintf(buf, "Your IP address is %s", inet_ntoa(cli.sin_addr));
  if(send(ns, buf, strlen(buf) + 1, 0) ==-1){
    perror("send");
    exit(1);
  }
  close(ns);
  close(sd);
}
