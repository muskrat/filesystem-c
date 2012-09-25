# C virtual file system make file

all:
	clang inode.c table.c main.c -o filesystem

inode:
	clang -c inode.c -o inode.o

table:
	clang -c table.c -o table.o

clean:
	rm -rf *o filesystem
