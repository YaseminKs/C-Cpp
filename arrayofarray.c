#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int main(){
	int n, i, j;
	printf( "Enter a number=> " );
	scanf( "%d", &n );
	for( i = 0 ; i < n ; i++ ){
		for( j = 0 ; j < n ; j++ ){
			if(  ( i == n / 2 ) || ( j == n / 2 ) || ( ( n % 2 == 0 ) && ( j == n / 2 - 1 ) || ( i == n / 2 - 1 ) ) ){
				printf( "1 " );
			}else{
				printf( "0 " );
			}
		} 
		printf( "\n" );
	}
	getch();
	return 0;
}
