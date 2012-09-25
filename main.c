/* Main program, command interpreter for virtual file system
 *
 * I K Stead, 25-09-2012
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

#define MAX_CMD_LEN 32

int main()
{
    Table *table = table_new();

    /* Command interpreter */
    char input[MAX_CMD_LEN]; /* Input buffer */
    
    while (strcmp(input, "quit"))
    {
        printf("> "); /* Prompt */
        gets(input);
        if (!strcmp(input, "make")) {
            /* Temporary assignment so I have some output to look at */
            int i = table_new_inode(table, 'f');
        }
        else if (!strcmp(input, "showall"))
            table_print_all(table);
    }

    /* Clean up */
    table_destroy(table);
    return EXIT_SUCCESS;
}
