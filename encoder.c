#include "encoder.h"
FILE * openFile(const char * Filename,const char * Mode)
{
	FILE * file;
    	if ((file = fopen(Filename, Mode)) ==NULL){      /*l'ouverture de fichier en Mode Read*/
    	printf("Error opening file \n");
    	exit(EXIT_FAILURE);
    	}
    	else return file;
}
    
char* allocMemory(FILE * file){
	char* output;
	int len;
	fseek(file, 0, SEEK_END);
	len = ftell(file);  /*calculer la taille du fichier*/
	fseek(file, 0, SEEK_SET);  /*inserer le curseur au debut*/
	output =(char*)calloc(len,sizeof(char)); /*la taille max de l'OUTPUT ne depasse pas la taille de fichier*/
	if (output == NULL) { /* On verifie que le systeme n'a pas renvoye un pointeur nul. */
    		puts("ERREUR : probleme de memoire.");
    		exit(EXIT_FAILURE);
	}
	else return output;
}

char* bitStuffingFile(FILE * file,char *output){
	char c;         /*pour parcourir le fichier*/
	int incr=0;    
	int count=5;   /* pour compter le bits successifs redendants*/
	char last_char;
	while(!feof(file)){
		c=fgetc(file);
    		if((c=='0')||(c=='1')){ 
    			output[incr]=c;
    			if(incr==0) last_char=c; /*pour initialiser la valeur de last_char*/
        		incr++;
        		if(last_char==c){
        			count--; /*on decremente le nombre de bits possibles qu'on peut l'inserer sans BitStuffing*/
        			if(count==0){     /* le nombre de bit est égal 5*/
			   		output[incr]=(char) (abs((c-48)-1)+48); /* on ajoute le bit opposé de celui qui se répéte*/
			    		count=5; /* on réinitialise le nombre de bits possibles qu'on peut l'inserer sans BitStuffing*/
			    		incr++;
		    		}
	        	}else {
	        	last_char=c;
	        	count=4;
	        	}
	        	
       		 }
  	  }
return output ;
}

char* bitStuffingString(char* output,char *input){
	int i;
	int len;
	char c;         /*pour parcourir le fichier*/
	int incr=0;    
	int count=5;   /* pour compter le bits successifs redendants*/
	char last_char;
	len=strlen(input);
	for(i=0;i<len+1;i++){
		c=input[i];
    		if((c=='0')||(c=='1')){ 
    			output[incr]=c;
    			if(incr==0) last_char=c; /*pour initialiser la valeur de last_char*/
        		incr++;
        		if(last_char==c){
        			count--; /*on decremente le nombre de bits possibles qu'on peut l'inserer sans BitStuffing*/
        			if(count==0){     /* le nombre de bit est égal 5*/
			   		output[incr]=(char) (abs((c-48)-1)+48); /* on ajoute le bit opposé de celui qui se répéte*/
			    		count=5; /* on réinitialise le nombre de bits possibles qu'on peut l'inserer sans BitStuffing*/
			    		incr++;
		    		}
	        	}else {
	        	last_char=c;
	        	count=4;
	        	}
	        	
       		 }
  	  }
return output ;
}
		
		
	
	
	
