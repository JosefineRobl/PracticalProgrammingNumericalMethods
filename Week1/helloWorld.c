#include <stdio.h>
#define MAX_USERID_LENGTH 32

void printHelloWorld(void){
	printf("Hello, World!\n");
}


void printHelloName(void){
	char username[MAX_USERID_LENGTH];
	cuserid(username);
	printf("Hello, %s!\n", username);	
}

int main(void){
	printf("----- Exercise A -----\n");
	printHelloWorld();
	printf("----- Exercise B -----\n");
	printHelloName();
	return 0;
}
