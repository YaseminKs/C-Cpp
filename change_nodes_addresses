#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
} *list1 = NULL, *list2 = NULL;

char buffer[ 100 ];
char number1[ 100 ];
char number2[ 100 ];

int numberoflist1[ 100 ];
int numberoflist2[ 100 ];

void readafile( char* filename, char* buff, int datalength ){
    FILE* fp;
    fp = fopen( filename, "r" );
    fread( buff, 1, datalength, fp );
    fclose( fp );
}

int chararrayoflength( char array[] ){
    int i = 0;
    while( array[ i ] != '\0' ){
        i++;
    }
    return i;
}

int arrayoflength( int array[] ){
    int i = 0;
    while( array[ i ] != '\0' ){
        i++;
    }
    return i;
}

void selectnumbers( ){
    int i = 0;
    int numbercontrol = 0;
    int counter1 = 0;
    int counter2 = 0;
    int charlength = chararrayoflength( buffer );
    while( i < charlength ){
        if( buffer[ i ] == '#' ){
            numbercontrol = 1;
        }else if( numbercontrol == 0){
            number1[ counter1 ] = buffer[ i ];
            counter1++;
        }else if( numbercontrol == 1 ){
            number2[ counter2 ] = buffer[ i ];
            counter2++;
        }
        i++;
    } 
}

int groupofthreesnumbers( int hundreds, int tens, int ones ){
    return 100 * hundreds + 10 * tens + ones;
}

void turnintogrupofthreesnumbers(){
    int i = 0;
    int number1length = chararrayoflength( number1 );
    while( i < number1length ){
        int hundreds = ( int )number1[ i ] - 48;
        int tens = ( int )number1[ i + 1 ] - 48;
        int ones = ( int )number1[ i + 2 ] - 48;
        int threesnumber = groupofthreesnumbers( hundreds, tens, ones );
        numberoflist1[ i / 3 ] = threesnumber;
        i = i + 3;
    }
    int j = 0;
    int number2length = chararrayoflength( number2 );
    while( j < number2length ){
        int hundreds = ( int )number2[ j ] - 48;
        int tens = ( int )number2[ j + 1 ] - 48;
        int ones = ( int )number2[ j + 2 ] - 48;
        int threesnumber = groupofthreesnumbers( hundreds, tens, ones );
        numberoflist2[ j / 3 ] = threesnumber;
        j = j + 3;
    }
}

struct node* createanode( int data ){
    struct node* new = ( struct node* )calloc( sizeof( struct node ), 1 );
    new -> data = data;
    new -> prev = NULL;
    new -> next = NULL;
    return new;
}

void linkednodes( struct node* tempold, struct node* tempnew ){
    tempold -> next = tempnew;
    tempnew -> prev = tempold;
}

void createalinkedlist( struct node** list, int numbers[] ){
    int i = 0;
    int numbersoflength = arrayoflength( numbers );
    struct node* tempold = NULL;
    struct node* tempnew = NULL;
    while(  i < numbersoflength ){
        if( i == 0 ){
            *list = createanode( numbers[ i ] );
            tempnew = *list;
        }else{
            tempold = tempnew;
            tempnew = createanode( numbers[ i ] );
            linkednodes( tempold, tempnew );
        }
        i++;
    }
}

void showalinkedlist( struct node* list ){
    struct node* iter = NULL;
    if( list != NULL ){
        iter = list;
        while( iter ){
            printf( "%d", iter -> data );
            iter = iter -> next;
        }
    }else{
        printf( "List is empty!!" );
    }
}

struct node* findanode( struct node* list, int index ){
    struct node* temp = NULL;
    temp = list;
    int i = 0;
    while( i < index ){
        temp = temp -> next;
        i++;
    }
    return temp;
}

void turnintoreverse( struct node** list ){
    struct node* prev = NULL;
    struct node* next = NULL;
    struct node* tempold = NULL;
    struct node* tempnew = *list;
    while( tempnew ){
        tempold = tempnew;
        tempnew = tempnew -> next;
        next = tempold -> next;
        prev = tempold -> prev;
        tempold -> next = prev;
        tempold -> prev = next;
        *list = tempold;
    }
}

void changethenodes( struct node** node1address, struct node** node2address ){
    struct node* node1 = *node1address;
    struct node* node2 = *node2address;
    if( node1 -> prev == NULL ){
        struct node* next1 = node1 -> next;
        struct node* next2 = node2 -> next;
        node1 -> next = next2;
        node2 -> next = next1;
        next1 -> prev = node2;
        next2 -> prev = next1;
        //address changing
        *node1address = node2;
        *node2address = node1;
    }else if( node1 -> next == NULL ){
        struct node* prev1 = node1 -> prev;
        struct node* prev2 = node2 -> prev;
        node1 -> prev = prev2;
        node2 -> prev = prev1;
        prev1 -> next = node2;
        prev2 -> next = node1;
        *node1address = node2;
        *node2address = node1;
    }else{
        struct node* next1 = node1 -> next;
        struct node* next2 = node2 -> next;
        struct node* prev1 = node1 -> prev;
        struct node* prev2 = node2 -> prev;
        node1 -> next = next2;
        node2 -> next = next1;
        node1 -> prev = prev2;
        node2 -> prev = prev1;
        next1 -> prev = node2;
        next2 -> prev = next1;
        prev1 -> next = node2;
        prev2 -> next = node1;
        *node1address = node2;
        *node2address = node1;
    }
}

void comparing(){
    int i = 0;
    int numberslength = arrayoflength( numberoflist1 );
    while( i < numberslength ){
        printf( "\n-------------------- Step : %d --------------------", i + 1 );
        struct node* node1 = findanode( list1, i );
        struct node* node2 = findanode( list2, i );
        if( node1 -> data > node2 -> data ){
            printf( "\n%d > %d ", node1 -> data, node2 -> data );
            turnintoreverse( &list1 );
            printf( "\nList is reversed!!" );
        }else if( node1 -> data == node2 -> data ){
            printf( "\n%d 0 %d ", node1 -> data, node2 -> data );
            turnintoreverse( &list2 );
        }else if( node1 -> data < node2 -> data ){
            printf( "\n%d < %d ", node1 -> data, node2 -> data );
            if( i == 0 ){
                changethenodes( &list1, &list2 );
            }else{
                changethenodes( &node1, &node2 );
            }
            printf( "\n%d and %d swapped places!!", node1 -> data, node2 -> data );
        }
        printf( "\nList1: " );
        showalinkedlist( list1 );
        printf( "\nList2: " );
        showalinkedlist( list2 );
        i++;
    }
}

int main(){
    readafile( "numbers.txt", buffer, 100 );
    printf( "\nRead data: %s\n", buffer );

    selectnumbers();
    printf( "Number 1: %s\n", number1 );
    printf( "Number 2: %s\n", number2);

    turnintogrupofthreesnumbers();
    printf( "\nNumber1List member1: %d\n", numberoflist1[ 0 ] );
    printf( "Number2List member1: %d\n", numberoflist2[ 0 ] );

    if( arrayoflength( numberoflist1) > 0 ){
        createalinkedlist( &list1, numberoflist1 );
    }
    if( arrayoflength( numberoflist2 ) > 0 ){
        createalinkedlist( &list2, numberoflist2 );
    }

    printf( "\nPre-comparison=> " );
    printf( "\nList1: " );
    showalinkedlist( list1 );
    printf( "\nList2: " );
    showalinkedlist( list2 );

    printf( "\n\nComparing!! " );
    comparing();

    printf( "\n\nPost-comparison: " );
    printf( "\nList1: " );
    showalinkedlist( list1 );
    printf( "\nList2: " );
    showalinkedlist( list2 );

    return 0;
}
