CC = clang
LD = $(CC)
CFLAGS = -std=c99 -Wextra -Wall -g
LDFLAGS =

all: testpatch

testpatch: testpatch.o ast.o image.o patchwork.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o *~ testpatch *.ppm
