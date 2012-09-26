/* Main program, command interpreter for virtual file system
 *
 * I K Stead, 25-09-2012
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

#define MAX_CMD_LEN 32

/* Functions called by commands in the interpreter */

/* Create a new file or dir file in given directory. Used in move,
 * mkdir, new
 */
void newfile(Table *table, Inode *w_dir, char type, char fname[])
{
    Inode *node = table_new_inode(table, type); /* Allocate a new inode */
    int index = node->id;                         /* Get its index */
    inode_dir_addentry(w_dir, index, fname);
    return;
}

int main()
{
    /* Create a root directory and point working directory to it */
    Table *table = table_new();
    Inode *root = table_new_inode(table, DIR_T);
    Inode *w_dir = root;

    /* Command interpreter */
    char input[MAX_CMD_LEN]; /* Input buffer */
    
    while (strcmp(input, "quit"))
    {
        printf("> "); /* Prompt */
        gets(input);
        if (!strcmp(input, "new")) {
            printf("Enter filename: ");
            gets(input);
            newfile(table, w_dir, FILE_T, input);
        }
        else if (!strcmp(input, "showall")) {
            table_print_all(table);
        }
        else {
            printf("Invalid command.\n");
        }
    }

    /* Clean up */
    table_destroy(table);
    return EXIT_SUCCESS;
}
