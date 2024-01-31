#include "utility.h"

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void pwd(char** args){
    char *buffer;
    buffer=(char *)malloc(100*sizeof(char));
    getcwd(buffer,100);
    printf("%s \n",buffer);
}

void cd(char** args){
    printf("this will be cd\n");
    for(int i = 0; args[i] != NULL; ++i){
        printf(" %s \n",args[i]);
    }
}

void clr(){

}

void dir(){

}

void environ(){

}

void echo(){

}

void help(){

}

void more(){

}

void pauseSH(){

}

