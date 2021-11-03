#include <stdio.h>

#include "bst.c"

#define LEVEL 3

void print_leveled( bst );
void print_level( int, bst );

int main() {
    bst T = NULL;
    int a[] = { 4, 3, 6, 8, 9, 10, 1, 5 };
    for( int i = 0; i < sizeof( a ) / sizeof( a[0] ) ; i++ )
        T = bst_insert( a[i], T );

    bst_print( "%d ", T, PRE_ORDER );

    print_leveled( T );
    printf( "\n\n" );
    print_level( LEVEL, T );

    T = bst_free( T );

    return 0;
}

void print_level( int h, bst T ) {
    if( !T ) return;
    if( h == 1 ) printf( "%d ", T->element );
    if( h > 1 ) {
        print_level( h - 1 , T->left );
        print_level( h - 1 , T->right );
    }
}

void print_leveled( bst T ) {
    int h = bst_height( T );
    for( int i = 1; i <= h ; i++ ) {
        printf( "\n%d: ", i );
        print_level( i, T );
    }
}


