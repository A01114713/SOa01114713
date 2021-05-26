#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argnum, char **argv){
    char *original = argv[1];
    char *destino = argv[2];
    char buffer;
    int size;
    FILE *foriginal, *fdestino;
    foriginal = fopen(original,"rb");
    fdestino = fopen(destino,"wb");
    while(fread(&buffer,sizeof(char),1,foriginal) ){
        if(buffer == '\n'){
            char *linea;
            size += 1;
            fseek(foriginal, -size, SEEK_CUR); //regresa al inicio de la linea
            linea = (char *) calloc(size, sizeof(char)); //arreglo de carecteres de tamaño size
            fread(linea,sizeof(char),size,foriginal); //leer la linea
            if(strstr(linea,"hola") == NULL){
                fwrite(&linea,sizeof(char),size,fdestino);
            }
            size = 0;
        } else {
            size += 1;
        }
    }
    fclose(foriginal);
    fclose(fdestino);

    return 0;
}
