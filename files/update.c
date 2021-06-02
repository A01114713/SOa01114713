#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	char *filename = argv[1];
	char *atributo = argv[2];
	char *palabra = argv[3];
	char *nuevoValor = argv[4];
	int iid;
	int isemestre;
	int inuevoValor;
	
	FILE *forigen;
	forigen = fopen(filename, "r+b");
	STUDENT newstudent;
	
	while(fread(&newstudent, sizeof(newstudent), 1, forigen)){
		if(strcmp(atributo, "name") == 0){
			if(strcmp(palabra, newstudent.name) == 0){
				strcpy(newstudent.name, nuevoValor);
				fseek(forigen, -1*sizeof(newstudent), SEEK_CUR); //nos regresamos una fila para poder rescribirla
				fwrite(&newstudent,sizeof(newstudent),1,forigen);
				fread(&newstudent,sizeof(newstudent),1,forigen);
			}
		} else if (strcmp(atributo, "lastname") == 0){
			if(strcmp(palabra, newstudent.lastname) == 0){
				strcpy(newstudent.lastname, nuevoValor);
				fseek(forigen, -1*sizeof(newstudent), SEEK_CUR);
				fwrite(&newstudent,sizeof(newstudent),1,forigen);
				fread(&newstudent,sizeof(newstudent),1,forigen);
			}
		} else if (strcmp(atributo, "id") == 0){
			iid = atoi(palabra);
			inuevoValor = atoi(nuevoValor);
			if(iid == newstudent.id){
				newstudent.id = inuevoValor;
				fseek(forigen, -1*sizeof(newstudent), SEEK_CUR);
				fwrite(&newstudent,sizeof(newstudent),1,forigen);
				fread(&newstudent,sizeof(newstudent),1,forigen);
			}
		} else if (strcmp(atributo, "semestre") == 0){
			isemestre = atoi(palabra);
			inuevoValor = atoi(nuevoValor);
			if(isemestre == newstudent.semestre){
				newstudent.semestre = inuevoValor;
				fseek(forigen, -1*sizeof(newstudent), SEEK_CUR);
				fwrite(&newstudent,sizeof(newstudent),1,forigen);
				fread(&newstudent,sizeof(newstudent),1,forigen);
			}
		}
	}
	fclose(forigen);
}