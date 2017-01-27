#include<stdio.h>
#include<stdlib.h>
#include <string.h>

FILE * openFile(const char * Filename,const char * Mode);
char* allocMemory(FILE * file);
char* bitStuffingFile(FILE * file,char *output);
char* bitStuffingString(char* output,char *input);
