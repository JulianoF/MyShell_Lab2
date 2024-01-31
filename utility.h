#ifndef UTILITY_H
#define UTILITY_H

struct Command {
	int id;
	char name[20];
	void (*functionptr)(char** args);
};

void pwd();
void cd(char** args);
void clr();
void dir(char** args);
void environ();
void echo(char** args);
void help();
void more();
void pauseSH();

void execute(struct Command* command, int params);

#endif