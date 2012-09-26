/* Inode table functions outlined in table.h
 *
 * I K Stead, 25-09-2012
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

Table *table_new()
{
    return malloc(sizeof(Table));
}

Inode *table_new_inode(Table *table, char t)
{
    int i = table->next_free_index;
    table->next_free_index ++;

    Inode *node = inode_alloc();
    inode_setid(node, i);
    inode_settype(node, t);

    table->table[i] = node;
    return node;
}

void table_clear_inode(Table *table, int index)
{
    int last = table->next_free_index;
    Inode *node = table->table[index];
    if (index < last && node != NULL)
        inode_clear(node);
    else
        printf("[table_clear_inode]: ");
        printf("index %i out of range / node empty\n", index);
}

int table_reallocate(Table *table, int index, char t)
{
    Inode *node = table->table[index];
    node = inode_alloc();
    inode_setid(node, index);
    inode_settype(node, t);
    return index;
}

Inode *table_get_inode(Table *table, int index)
{
    if (index < table->next_free_index)
        return table->table[index];
    else {
        printf("[table_get_inode]: index %i out of range\n", index);
        return NULL;
    }
}

void table_destroy(Table *table)
{
    int i;
    int last = table->next_free_index;
    for (i = 0; i < last; i++) {
        free(table_get_inode(table, i));
    }
    free(table);
}

void table_print_all(Table *table)
{
    int i;
    int last = table->next_free_index;
    for (i = 0; i < last; i++) {
        inode_print(table->table[i]);
    }
    return;
}
