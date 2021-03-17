#include <stdio.h>
#include <string.h>

int main(int numarg, char **argv){
	char reves[10];
	for(int i = numarg; 1 < i; i--){
		strcat(reves, argv[i]);
		strcat(reves, " ");
	}
	return 0;
}