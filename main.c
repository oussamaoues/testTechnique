
#include <string.h>
#include "encoder.h"

FILE *fp;       //le fichier contenant les données à stocker dans le disque dur
char *output_encoder;  //chaine de caractéres contenant la sortie de l'encodeur

int main(){

fp = openFile("EncoderINPUT", "r");
output_encoder=allocMemory(fp); //allouer la mémoire nécessaire pour les données de sortie de l'encodeur
output_encoder= bitStuffing(fp,output_encoder);   //appliquer le bit stuffing au données de fichier INPUT
printf("la sortie de l'encodeur %s",output_encoder);
free(output_encoder); //libérer la mémoire allouée
fclose(fp);  //fermer le fichier
return 0;
}
