/* Inode data structure and functions that create, destroy and 
 * manipulate inodes
 *
 * I K Stead, 25-09-2012
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_T      'f'
#define DIR_T       'd'
#define FSIZE       1024    /* Maximum byte length of file */
#define NAME_LEN    32      /* Maximum length of file names */

/* Defines the format for directory entries */
static const char DATA_SEP = ':';
static const char ENTRY_SEP = '\n';

/* The inode data structure */
typedef struct inode_struct {
    int id;             /* Corresponds with index in table */
    char type;          /* 'f' for file or 'd' for dir */
    char data[FSIZE];   /* Contains file data */
} Inode;

/* Represents a directory entry */
typedef struct entry_struct {
    int index;
    char name[NAME_LEN];
} Entry;

/* Allocate memory for new inode and return pointer */
Inode *inode_alloc()
{
    Inode *node = malloc(sizeof(Inode));
    return node;
}
/* Clear contents of inode */
void inode_clear(Inode *node)
{
    node = NULL;
}
/* Free Inode memory */
void inode_free(Inode *node)
{
    free(node);
}
/* Set inode ID. This is called when a new inode is created in the inode
 * table to set the inode's ID to its index in the table
 */
void inode_setid(Inode *node, int id)
{
    node-> id = id;
}
/* Set inode type. Inodes can be either normal files ('f') or
 * directories ('d').
 */ 
void inode_settype(Inode *node, char type)
{
    if (type != 'd' && type != 'f')
        printf("[inode_settype] invalid filetype: %c\n", type);
    else 
        node-> type = type;
    return;
}
/* Add string to the end of inode data field. */
void inode_append(Inode *node, char string[])
{
    char *data = node-> data;
    if (strlen(string) > FSIZE)
        printf("[inode_append] data too long: %s\n", string);
    else
        strcat(data, string);
    return;
}
/* Debugging: print contents of inode to stdout */
void inode_print(Inode *node)
{
    int id = node ->id;
    char t = node ->type;
    char *s = node ->data;
    printf("Contents of inode %i:\n  %c\n  '%s'\n", id, t, s);
    return;
}
/* Given inode index and filename, return a properly formatted dir 
 * entry string.
 */
void inode_dir_formatentry(char *entry, int index, char fname[])
{
    if (strlen(fname) > NAME_LEN)
        printf("[inode_dir_formatentry] filename %s too long\n", fname);
    else 
        sprintf(entry, "%s%c%i%c", fname, DATA_SEP, index, ENTRY_SEP);
}
/* Add a directory entry to given inode, if it is a directory 
 */
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
/* Parse directory entries for inode number associated with given filename */
int inode_dir_seek(Inode *dnode, char fname[])
{
    char* entry_buf;
    char* data_buf;
    char* node_data = dnode->data;
    char* s = fname; /* Local copy of fname due to way strtok works */
    
    printf("%s\n", entry_buf); /* <<< BUG HERE = entry is always null so loop never goes */

    while (entry_buf != NULL) {
        entry_buf = strtok(node_data, &ENTRY_SEP);
        s = NULL; /* As processing same string, cf. man 3 strtok */
        data_buf = strtok(entry_buf, &DATA_SEP);
        printf("%s\n", data_buf);
        
        if (!strcmp(data_buf, fname)) {
            data_buf = strtok(NULL, &DATA_SEP);
            return (int)data_buf;
        }
    }
    return -1;
}
