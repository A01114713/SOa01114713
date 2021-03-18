#include <stdio.h>

int main(int numarg, char **argv){ //Main puede recibir dos argumentos, numarg que dicta el numero de argumentos
	for(int i = 1; i < numarg; i++){
		printf("Hello world %s\n",argv[i]);	
	./}
	return 0;
}