#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
} *queue = NULL, *end = NULL, *stack = NULL;

struct node* createanode( int value ){
    struct node* new = ( struct node* )calloc( sizeof( struct node ), 1 );
    new -> data = value;
    new -> next = NULL;
    return new;
}

void linkednodes( struct node* tempold, struct node* tempnew ){
    tempold -> next = tempnew;
}

void enqueue( struct node** queue, int value ){
    if( *queue == NULL ){
        *queue = createanode( value );
        end = *queue;
    }else{
        struct node* temp = ( struct node* )calloc( sizeof( struct node ), 1 );
        temp = createanode( value );
        linkednodes( end, temp );
        end = end -> next;
    }
}

void showthe( struct node* root ){
    while( root ){
        printf( "%d ", root -> data );
        root = root -> next;
    }
}

void createthequeue(){
    for( int i = 1 ; i <= 10 ; i++ ){
        enqueue( &queue, i * 9 );
    }
    printf( "\nThe queue is: ");
    showthe( queue );
}

void push( struct node** stack, int value ){
    if( *stack == NULL ){
        *stack = createanode( value );
    }else{
        struct node* temp = ( struct node* )calloc( sizeof( struct node ), 1 );
        temp = createanode( value );
        struct node* iter = *stack;
        while( iter -> next != NULL ){
            iter = iter -> next;
        }
    linkednodes( iter, temp );
    }
}

int pop( struct node* stack ){
    if( stack == NULL ){
        printf( "\nThe stack is empty!!" );
        return -1;
    }
    if( stack -> next == NULL ){
        int value = stack -> data;
        free( stack );
        return value;
    }
    struct node* iter = stack;
    while( iter -> next -> next != NULL ){
        iter = iter -> next;
    }
    struct node* temp = iter -> next;
    int value = temp -> data;
    iter -> next = NULL;
    free( temp );
    return value;
}

void createthestack(){
    int total = 0;
    int counter = 0;
    struct node* iter1 = queue;
    while( iter1 ){
        total = total + iter1 -> data;
        counter += 1;
        iter1 = iter1 -> next;
    }
    int average = total / counter;
    struct node* iter2 = queue;
    while( iter2 ){
        if( iter2 -> data > average ){
            push( &stack, iter2 -> data );
        }
        iter2 = iter2 -> next;
    }
    printf( "\nThe stack is: " );
    showthe( stack );
}

int array[ 10 ];

void createthearray(){
    for( int i = 0 ; i < 5 ; i++ ){
        array[ i ] = pop( stack );
    }
    printf( "\nThe array is: " );
    for( int i = 0 ; i < 5 ; i++ ){
        printf( "%d ", array[ i ] );
    }
}

int main(){
    createthequeue();
    createthestack();
    createthearray();
    return 0;
}
