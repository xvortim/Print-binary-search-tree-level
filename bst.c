#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bst.h"

static bst_node *create_node( bst_element_type x, bst_position left, bst_position right ) {
    bst_node *p_node = ( bst_node * )malloc( sizeof( bst_node ) );
    assert( p_node != NULL );
    p_node->element = x;
    p_node->left = left;
    p_node->right = right;
    return p_node;
}

static void printR( char *fmt, bst T, bst_traversal trav ) {
    if( bst_is_empty( T ) ) return;
    if( trav == PRE_ORDER ) {
        printf( fmt, T->element );
        printR( fmt, T->left, trav );
        printR( fmt, T->right, trav );
    }
    else if( trav == IN_ORDER ) {
        printR( fmt, T->left, trav );
        printf( fmt, T->element );
        printR( fmt, T->right, trav );
    }
    else if( trav == POST_ORDER ) {
        printR( fmt, T->left, trav );
        printR( fmt, T->right, trav );
        printf( fmt, T->element );
    }
}

bst bst_free( bst T ) {
    if( bst_is_empty( T ) ) return T;
    T->left = bst_free( T->left );
    T->right = bst_free( T->right );
    free( T );
    return NULL;
}

int bst_is_empty( bst T ) {
    return T == NULL;
}

int bst_height( bst T ) {
    if( bst_is_empty( T ) ) return 0;
    int lheight = bst_height( T->left );
    int rheight = bst_height( T->right );
    return 1 + ( lheight > rheight ? lheight : rheight );
}

bst bst_insert( bst_element_type x, bst T ) {
    if( bst_is_empty( T ) ) return create_node( x, NULL, NULL );
    if( x == T->element ) return T;
    else if( x < T->element ) T->left = bst_insert( x, T->left );
    else T->right = bst_insert( x, T->right );
}

void bst_print( char *fmt, bst T, bst_traversal trav ) {
    printf( "\n[ " );
    printR( fmt, T, trav );
    printf( "]\n" );
}

