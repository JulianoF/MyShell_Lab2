#ifndef UTILITY_H
#define UTILITY_H

struct Command {
	int id;
	char name[20];
	void (*functionptr)();
};

void pwd();
void cd();
void clr();
void dir();
void environ();
void echo();
void help();
void more();
void pause();
void quit();

void execute(struct Command* command, int params);

#endif