#ifndef BST_H
#define BST_H

typedef int bst_element_type;
typedef enum { PRE_ORDER, IN_ORDER, POST_ORDER } bst_traversal;

typedef struct _node {
    bst_element_type element;
    struct _node *left;
    struct _node *right;
} bst_node;

typedef bst_node *bst;
typedef bst_node *bst_position;

bst bst_free( bst );

int bst_is_empty( bst );
int bst_height( bst );

bst bst_insert( bst_element_type, bst );

void bst_print( char *, bst, bst_traversal );

#endif
