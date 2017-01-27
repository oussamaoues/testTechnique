#include "encoder.h"

FILE *fp;       /*le fichier contenant les données a stocker dans le disque dur*/
char *output_encoder=NULL;  /*chaine de caracteres contenant la sortie de l'encodeur*/

int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("l'encodeur ne recoit aucun argument, il execute le contenu de fichier EncoderINPUT \n");
		fp = openFile("EncoderINPUT", "r");
		output_encoder=allocMemory(fp); /*allouer la memoire necessaire pour les donnees de sortie de l'encodeur*/
		output_encoder= bitStuffingFile(fp,output_encoder);  /*appliquer le bit stuffing au donnees  INPUT*/
		fclose(fp);  /*fermer le fichier*/
	}else if (argc > 1){
		int len;
		fp = openFile("EncoderINPUT", "r");
		len=strlen(argv[1]);
		output_encoder = (char*)calloc(len,sizeof(char));
		output_encoder= bitStuffingString(output_encoder,argv[1]);
		}
	
	printf("la sortie de l'encodeur %s",output_encoder);
	free(output_encoder); /*liberer la memoire allouee*/
	return 0;
}
