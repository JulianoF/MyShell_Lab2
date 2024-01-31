#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

#include "utility.h"

struct Command commandDict[] = { //a struct of command structs to hold all possible commands
	{0,"pwd",pwd},
	{1,"cd",cd},
	{2,"clr",clr},
	{3,"dir",dir},
	{4,"environ",environ},
	{5,"echo",echo},
	{6,"help",help},
	{7,"more",more},
	{8,"pause",pauseSH}
}; 

char** args; //args parsed from user input
size_t numArgs; //num of args found

void init(); //declare init function
void shell_loop(); //declare shell_loop function
void cleanup(int); //declare cleanup function

void handle_sigstp(int); //declare custom signal handling function
char** argParse(char*,size_t*); //declare argparse helper function

int main(){
	//main shell init, run and cleanup process
	init();
	shell_loop();
	cleanup(0);
	return 0;
}
///////////////////////////////////////////////////////
void handle_sigstp(int sig){ //Custom sigstp handler
	printf("\nCTRL-Z detected: Quitting Shell \n");
	cleanup(1);
}

char** argParse(char* args, size_t* numArgs){ //function to parse the argument provided in user input
	
	char** parsed_args = (char**)malloc(sizeof(char*) * 10); //allocate some room in mem for the parsed args
	*numArgs = 0;

	char* token = strtok(args," ");//tokenize while using space a delimiter
	while(token != NULL){ //while tokens are found
		parsed_args[*numArgs] =  strdup(token);
		if(parsed_args[*numArgs] == NULL){
			exit(EXIT_FAILURE);
		}
		(*numArgs)++;
		if(*numArgs % 10 == 0){
			parsed_args = (char**)realloc(parsed_args,sizeof(char*) * (*numArgs + 10));
			if(parsed_args == NULL){
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL," ");
	}
	return parsed_args;
}

///////////////////////////////////////////////////////
void init(){
	//Set enviro variables
	numArgs = 0;

	//Set any signal handlers
	signal(SIGTSTP,handle_sigstp);
}

void shell_loop(){
	//loop and wait for user input and envoke command execution pipeline
	while(1){
		printf("Myshell> ");

		char input[150];		

		if(fgets(input,sizeof(input),stdin) != NULL){
			size_t len = strcspn(input,"\n");
			if((len == 0 && input[len] == '\n') || input[0] == ' '){
				continue;
			}
			if(input[len] == '\n'){
				input[len] = '\0';
			}
			args = argParse(input,&numArgs);
		}else{
			printf("\n");
			continue;
		}

		if(strcmp(args[0],"pwd") == 0){
			commandDict[0].functionptr(NULL);
		}

		if(strcmp(args[0],"cd") == 0){
			commandDict[1].functionptr(args);
		}
		if(strcmp(args[0],"clr") == 0){
			commandDict[2].functionptr(NULL);
		}
		if(strcmp(args[0],"dir") == 0){
			commandDict[3].functionptr(args);
		}
		if(strcmp(args[0],"environ") == 0){
			commandDict[4].functionptr(NULL);
		}
		if(strcmp(args[0],"echo") == 0){
			commandDict[5].functionptr(args);
		}
		if(strcmp(args[0],"help") == 0){
			commandDict[6].functionptr(NULL);
		}
		if(strcmp(args[0],"pause") == 0){
			commandDict[7].functionptr(NULL);
		}
		if(strcmp(args[0],"quit") == 0){
			break;
		}	
	}
}

void cleanup(int status){
	printf("Cleaning up and terminating shell \n");
	//clean up and error handle
	if(numArgs > 0){
		for(size_t i = 0; i < numArgs; i++){
			free(args[i]);
		}
		free(args);
	}

	switch (status){
		case 0:
			return;
		case 1:
			exit(0);
		default:
			return;
	}
}
