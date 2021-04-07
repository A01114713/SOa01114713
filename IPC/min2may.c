#include <unistd.h>
#include <ctype.h>

int main(){
	char minC;
	char mayC;
	
	while(read(0, &minC, 1)){ //read regresa 0 cuando ya no haya nada que leer
		mayC = toupper(minC);
		write(1, &mayC, 1);
	}
	return 0;
}