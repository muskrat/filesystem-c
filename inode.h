/* Defined in inode.c: inode data structure and functions that create,
 * destroy and manipulate inodes
 * 
 * I K Stead, 25-09-2012
 */
#define FILE_T  'f'
#define DIR_T  'd'
#define FSIZE   1024  /* Maximum byte length of file */

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


