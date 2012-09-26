/* Defined in inode.c: inode data structure and functions that create,
 * destroy and manipulate inodes
 * 
 * I K Stead, 25-09-2012
 */
#define FILE_T      'f'
#define DIR_T       'd'
#define FSIZE       1024    /* Maximum byte length of file */
#define NAME_LEN    32      /* Maximum length of file names */

#define DATA_SEP    ':'     /* Defines the foramt for directory entries */
#define ENTRY_SEP   '\n'

typedef struct inode_struct {
    int id;             /* Corresponds with index in table */
    char type;          /* 'f' for file or 'd' for dir */
    char data[FSIZE];   /* Contains file data */
} Inode;

/* Functions */

/* Allocate memory for new inode and return pointer */
Inode *inode_alloc();

/* Clear contents of inode */
void inode_clear(Inode *node);

/* Free Inode memory */
void inode_free(Inode *node);

/* Set inode ID */
void inode_setid(Inode *node, int id);

/* Set inode type */ 
void inode_settype(Inode *node, char type);

/* Append data to inode data field */
void inode_append(Inode *node, char string[]);

/* Print contents of inode to stdout */
void inode_print(Inode *node);

/* Given inode index and filename, return a properly formatted dir entry */
void inode_dir_formatentry(char *entry, int index, char fname[]);

/* Add a directory entry to given inode, if it is a directory */
void inode_dir_addentry(Inode *dnode, int index, char fname[]);


