CC=gcc
CFLAGS=
OBJS=ch2_1.o
LIBS=
all : ch2_1.out

ch2_1.out : $(OBJS)
	$(CC) $(CFLAGS) -o ch2_1.out $(OBJS) $(LIBS)

ch2_1.o : ch2_1.c
	$(CC) $(CFLAGS) -c ch2_1.c

clean:
	rm -f $(OBJS) *.o core

