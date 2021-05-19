#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main (int argcnum, char **argv){
	char *path = argv[1]; //cadena de char que guardara la ruta
	struct stat sb; 
	if(stat(path, &sb) == -1){
		printf("Error, el archivo no existe \n");
		return -1;
	}
	if(S_ISDIR(sb.st_model)){ //si esto es verdadero, entonces es un directorio
		printf("Es un directorio \n");
	}
	if(S_ISREG(sb.st_model)){
		printf("Es un archivo normal \n");
	}
}