# Juliano Falotico, 100658311 - Operating Systems - Lab2
all: myshell myshellDEBUG

myshell: myshell.c utility.c utility.h
	gcc -Wall myshell.c utility.c -o myshell

myshellDEBUG: myshell myshell.c utility.c utility.h
	gcc -Wall -g myshell.c utility.c -o myshellDEBUG