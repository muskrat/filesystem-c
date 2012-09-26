/* Inode functions outlined in inode.c
 *
 * I K Stead, 25-09-2012
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inode.h"


Inode *inode_alloc()
{
    Inode *node = malloc(sizeof(Inode));
    return node;
}

void inode_clear(Inode *node)
{
    node = NULL;
}

void inode_free(Inode *node)
{
    free(node);
}

void inode_setid(Inode *node, int id)
{
    node-> id = id;
}

void inode_settype(Inode *node, char type)
{
    if (type != 'd' && type != 'f')
        printf("[inode_settype] invalid filetype: %c\n", type);
    else 
        node-> type = type;
    return;
}

void inode_append(Inode *node, char string[])
{
    char *data = node-> data;
    if (strlen(string) > FSIZE)
        printf("[inode_append] data too long: %s\n", string);
    else
        strcat(data, string);
    return;
}

void inode_print(Inode *node)
{
    int id = node ->id;
    char t = node ->type;
    char *s = node ->data;
    printf("Contents of inode %i:\n  %c\n  '%s'\n", id, t, s);
    return;
}

/* Functions which act on on directories */

void inode_dir_formatentry(char *entry, int index, char fname[])
{
    if (strlen(fname) > NAME_LEN)
        printf("[inode_dir_formatentry] filename %s too long\n", fname);
    else 
        sprintf(entry, "%s%c%i%c", fname, DATA_SEP, index, ENTRY_SEP);
}

void inode_dir_addentry(Inode *dnode, int index, char fname[])
{
    int id = dnode->id;
    if (dnode->type != DIR_T)
        printf("[inode_dir_addentry] inode %i not directory\n", id);
    else {
        char entry[NAME_LEN];
        inode_dir_formatentry(entry, index, fname);
        inode_append(dnode, entry);
    }
}
