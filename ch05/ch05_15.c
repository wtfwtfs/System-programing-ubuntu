#include <sys/time.h>
#include <stdio.h>

int main(){
  struct timeval tv;

  gettimeofday(&tv, NULL);
  printf("Time(sec) : %d\n", (int)tv.tv_sec);
  printf("Time(micro-sec) : %d\n", (int)tv.tv_usec);
}
