#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
  int fd, pagesize, length;
  caddr_t addr;

  pagesize = sysconf(_SC_PAGESIZE);
  length = 1*pagesize;

  if((fd = open("m.dat", O_RDWR | O_CREAT | O_TRUNC, 0666)) ==-1){
    perror("open");
    exit(1);
  }

  if(ftruncate(fd, (off_t) length) == -1){
    perror("ftruncate");
    exit(1);
  }

  addr = mmap(NULL, length, PROT_READ|PROT_WRITE,MAP_SHARED, fd, (off_t)0);
  if(addr ==MAP_FAILED){
    perror("mmap");
    exit(1);
  }

  close(fd);

  strcpy(addr, "ftruncate Test\n");
}
