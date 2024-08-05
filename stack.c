#include<stdio.h>
#include<stdlib.h>

int studentNumbers [] = { 3463, 36734, 4732 };
char* studentNames [] = { " AAAA ", " BAAA ", " ACSDS " };

struct student {
	
	char* studentName;
	int studentNumber;
	struct student* nextStudent;
	
};

typedef struct student Student;

void printStack( Student* headOfStack );
void popStudent( Student** headOfStack, Student* temporaryStudent );
void pushStudent( Student** headOfStack, int studentNumber, char* studentName );

int main ( void ){
	
	Student* headOfStack = NULL;
	Student* temporaryStudent = ( Student* )malloc( sizeof( Student ) );
	
	//Print an empty stack
	printStack( headOfStack );
	//Print an empty stack
	
	//Push students to stack
	pushStudent( &headOfStack, *( studentNumbers + 0 ), *( studentNames + 0 ) );
	pushStudent( &headOfStack, *( studentNumbers + 1 ), *( studentNames + 1 ) );
	pushStudent( &headOfStack, *( studentNumbers + 2 ), *( studentNames + 2 ) );
	printStack( headOfStack );
	//Push students to stack
	
	//Pop students from stack
	printf( " \nPop students from stack\n " );
	popStudent( &headOfStack, temporaryStudent );
	printStack( headOfStack );
	printf( " Removed student from stack--> Number:%-6d Name:%-s\n ", ( *temporaryStudent ).studentNumber, temporaryStudent->studentName );
	//Pop students from stack
	
	//Pop students from stack
	printf( " \nPop students from stack\n " );
	popStudent( &headOfStack, temporaryStudent );
	printStack( headOfStack );
	//Pop students from stack
	
	//Pop students from stack
	printf( " \nPop students from stack\n " );
	popStudent( &headOfStack, temporaryStudent );
	printStack( headOfStack );
	//Pop students from stack
	
	return 0;
	
}

void printStack( Student* headOfStack ){
	
	Student* currentStudent = headOfStack;
	
	if ( currentStudent == NULL ){
		printf( " There is no student in stack... \n " );
	}
	else{
		while( currentStudent != NULL ){
			printf( " Number:%-6d Name:%-s \n ", currentStudent->studentNumber, currentStudent->studentName );
			currentStudent = currentStudent->nextStudent;
		}
	}
	
}

void popStudent( Student** headOfStack, Student* temporaryStudent ){
	
	Student* currentStudent = ( *headOfStack );
	
	if( currentStudent == NULL ){
		printf( " popStudent: There is no student in the stack...\n " );
	}
	else{
		temporaryStudent->studentName = currentStudent->studentName;
		temporaryStudent->studentNumber = currentStudent->studentNumber;
		
		//Set new head of stack
		( *headOfStack ) = currentStudent->nextStudent;
		//Set new head of stack
		
		//Delete student from stack
		free( headOfStack );
		//Delete student from stack
	}
	
}

void pushStudent( Student** headOfStack, int studentNumber, char* studentName ){
	
	Student* newStudent = ( Student* )malloc( sizeof( Student ) );
	
	if( newStudent == NULL ){
		printf( " pushStudent: There is no space for new student...\n " );
		exit( EXIT_FAILURE );
	}
	else{
		newStudent->studentName = studentName;
		newStudent->studentNumber = studentNumber;
		newStudent->nextStudent = ( *headOfStack );
		
		//Set new head of stack
		( *headOfStack ) = newStudent;
		//SEt new head of stack
	}
	
}
