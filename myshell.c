#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

#include "utility.h"


struct Command commandDict[] = {
	{0,"pwd",pwd},
	{1,"cd",cd}
}; 

void init(); //declare init function
void shell_loop(); //declare shell_loop function
void cleanup(); //declare cleanup function

void handle_sigstp(int);

int main (){

	init();
	shell_loop();
	cleanup(0);
	return 0;
}

void handle_sigstp(int sig){
	printf("CTRL-Z detected: Quitting Shell \n");
	cleanup(1);
}

void init(){
	//Set enviro variables

	//Set any signal handlers
	signal(SIGTSTP,handle_sigstp);
}

void shell_loop(){
	//loop and wiat for user input and envoke command execution pipeline
	while(1){
		printf("Myshell> ");
		char input[100];
		scanf("%s",input);
		if(strcmp(input,"quit") == 0){
			char* test[] = {"testarg1","testarg2","testarg3",NULL};
			commandDict[1].functionptr(test);
			break;
		}	
	}
}

void cleanup(int status){
	printf("Cleaning up and terminating shell \n");
	//clean up and error handle

	switch (status){
		case 0:
			return;
		case 1:
			exit(0);
		default:
			return;
	}
}
