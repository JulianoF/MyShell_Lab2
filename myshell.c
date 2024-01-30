#include <stdio.h>
#include "utility.h"

struct Command commandDict[] = {
	{0,"pwd",pwd},
	{1,"cd",cd}
}; 

void init(); //declare init function
void shell_loop(); //declare shell_loop function
void cleanup(); //declare cleanup function

int main (){

	init();
	shell_loop();
	cleanup();
	return 0;

}

void init(){

}

void shell_loop(){

	while(1){
		printf("Myshell> ");
		int in;
		scanf("%d",&in);
		if(in == 1){
			commandDict[0].functionptr();
			break;
		}	
	}
}

void cleanup(){
	printf("Cleaning up and terminating shell \n");
	//clean up and error handle
}
