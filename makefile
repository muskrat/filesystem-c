# C virtual file system make file

all:
	clang main.c -o filesystem

clean:
	rm -rf *o filesystem
