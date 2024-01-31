#ifndef UTILITY_H
#define UTILITY_H

struct Command {
	int id;
	char name[20];
	void (*functionptr)(char** args);
};

void pwd(char** args);
void cd(char** args);
void clr();
void dir();
void environ();
void echo();
void help();
void more();
void pauseSH();

void execute(struct Command* command, int params);

#endif