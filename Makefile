CC = clang
CFLAGES = -Wall -Wextra -std=c11 -pedantic -ggdb

heap:main.c
	$(CC) $(CFLAGES) main.c -o heap

clean:
	rm ./heap
