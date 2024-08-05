#include<stdio.h>
#include<string.h>

void reverse( char array[] ){
	int i, longer, shadow;
	longer = strlen( array );
	for( i = 0 ; i <= longer/2 ; i++ ){
		shadow = array[ i ];
		array[ i ] = array[ longer - 1 - i ];
		array[ longer - 1 - i ] = shadow;
	}
}

int main(){
	char text[ 300 ];
	scanf( "%s", text );
	reverse( text );
	printf( "%s", text );
	return 0;
}
