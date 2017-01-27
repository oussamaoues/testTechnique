
#include <string.h>
#include "encoder.h"

FILE *fp;       /*le fichier contenant les données a stocker dans le disque dur*/
char *output_encoder;  /*chaine de caracteres contenant la sortie de l'encodeur*/

int main(int argc, char *argv[])
{
fp = openFile("EncoderINPUT", "r");
output_encoder=allocMemory(fp); /*allouer la memoire necessaire pour les donnees de sortie de l'encodeur*/
output_encoder= bitStuffing(fp,output_encoder);   /*appliquer le bit stuffing au donnees de fichier INPUT*/
printf("la sortie de l'encodeur %s",output_encoder);
free(output_encoder); /*liberer la memoire allouee*/
fclose(fp);  /*fermer le fichier*/
return 0;
}
