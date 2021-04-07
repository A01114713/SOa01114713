#include <unistd.h>
#include <ctype.h>

int main(){
	char c;
	int lineas;
	
	while(read(0, c, 1)){
		if(c == '\n'){
			lineas++;
		}
	}
	printf(lineas);
	return 0;
}