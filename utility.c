#include "utility.h"

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void pwd(){
    char *buffer;
    buffer=(char *)malloc(150*sizeof(char));
    getcwd(buffer,150);
    printf("%s \n",buffer);
    free(buffer);
}

void cd(char** args){
    printf("this will be cd\n");
    for(int i = 0; args[i] != NULL; ++i){
        printf("%s \n",args[i]);
    }
}

void clr(){
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO,CLEAR_SCREEN_ANSI,12);
}

void dir(char** args){

}

void environ(){

}

void echo(char** args){

}

void help(){

}

void more(){

}

void pauseSH(){

}

