#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int numarg, char **argv){
	
	if(numarg == 3){ //Verificar si el argumento tiene la forma requerida
        char *path1 = argv[1];
        char *path2 = argv[2];
        char direction[100];
        struct stat sb1;
        struct stat sb2;
		
        if(stat(path1,&sb1) != -1){ //Verificar si existe el archivo1
            if(S_ISREG(sb1.st_mode)){ //Verificar si path1 es un archivo
		        if(stat(path2,&sb2) == -1){//Verificar si existe el archivo2
                	//No existe
					//renombrar
                    link(path1,path2);
                    unlink(path1);
                    printf("%s se renombró a %s. \n",path1,path2);
					
                }else{
					//Existe
                    if(S_ISDIR(sb2.st_mode)){ //Verificar si el path2 es un directorio
                        //mover
                        strcat(direction,path2);
                        strcat(direction,"/");
                        strcat(direction,path1);
                        link(path1,direction);
                        unlink(path1);
                        printf("El archivo se ha movido a %s\n",direction);
						
                    }else{
                        printf("Error: El segundo archivo ya existe\n"); 
                        return -1;
                    }
                }
				
            }else{
                printf("Error: El primer argumento no es un archivo\n"); 
                return -1;
            }
			
        }else{
    		printf("Error: El primer archivo no existe\n");
            return -1;
        }
		
	}else{
		printf("Error: Ingrese argumentos validos\n");
	}
	return 0;
}