/* Defined in table.c: inode table data structure and functions to create,
 * destroy and manipulate it
 *
 * I K Stead
 *
 * TODO: Need some way of reallocating freed inode indices
 */
#include "inode.h"

#define MAX_FILES   1024
#define START_INDEX 0

typedef struct table_struct {
    int next_free_index;    /* Next unallocated inode number */
    Inode *table[MAX_FILES]; /* The array which stores pointers to inodes */
} Table;

/* Functions */

/* Return pointer to new table */
Table *table_new();

/* Create a new inode at next free index. Returns index of new inode */
int table_new_inode(Table *table, char t);

/* Clear inode at given index */
void table_clear_inode(Table *table, int index);

/* Reallocate given index to a new inode. Returns index of new node */
int table_reallocate(Table *table, int index, char t);

/* Cleanup: deallocate all inodes and then table itself */
void table_destroy(Table *table);

/* Return inode pointer at given index */
Inode *table_get_inode(Table *table, int index);

/* Print contents of inode table to stdout */
void table_print_all(Table *table);
