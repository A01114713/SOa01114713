#include <signal.h> //libreria para señales
#include <stdio.h>
#include <unistd.h> //libreria para sleep
#include <stdbool.h>

bool signalBool = false;

void signalHandler(int sig){
	printf("Recibi segnal %d\n", sig);
	signalBool = true;
}

int main(){
	signal(2, signalHandler); //cuando recibas una señal 15, ejecuta la funcion signalHandler
	signal(15, signalHandler);
	while(1){
		if(signalBool){
			break;
		}
		printf("Trabajando\n");
		sleep(1);
	}
	printf("Ya voy a terminar\n");
	return 0;
}