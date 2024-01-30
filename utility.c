#include "utility.h"

#include <string.h>
#include <stdio.h>


void pwd(char** args){
    printf("this will be pwd\n");
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

void pause(){

}

