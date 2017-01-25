#include<stdio.h>
#include<stdlib.h>

FILE * openFile(const char * Filename,const char * Mode);
char* allocMemory(FILE * file);
char* bitStuffing(FILE * file,char *output);
