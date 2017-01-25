
#include <string.h>
#include "encoder.h"

FILE *fp;       //le fichier contenant les données à stocker dans le disque dur
char *output_encoder;

int main(){

fp = openFile("EncoderINPUT", "r");
output_encoder=allocMemory(fp);
output_encoder= bitStuffing(fp,output_encoder);
printf("la sortie de l'encodeur %s",output_encoder);
free(output_encoder);
fclose(fp);
return 0;
}
