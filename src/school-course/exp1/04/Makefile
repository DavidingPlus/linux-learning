CC = gcc
CFLAGS = -Wall -Wextra -std=c11

school-course-exp1-04: main.o add.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c add.h
	$(CC) $(CFLAGS) -c -o $@ main.c

add.o: add.c config.h
	$(CC) $(CFLAGS) -c -o $@ add.c

.PHONY: clean
clean:
	rm -f school-course-exp1-04 main.o add.o
