#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> //para funcion wait
#include <signal.h>

void signalHandler(int sig){
	int pidHijoTerminado = wait(NULL);
	printf("Mi hijo terminó \n", pidHijoTerminado);
}

int main(){
	signal(17, signalHandler); //METODO ASINCRONO, solo hay que registrar la señal una vez
	int pid = fork(); //pid del proceso hijo

	if(pid == 0){ //proceso hijo
		printf("Soy el proceso hijo\n");
		
	} else {
		printf("Soy el proceso padre y mi hijo es %d\n", pid);
		//pidHijoTerminado = wait(NULL); METODO SINCRONO
		while(1){
			printf("Trabajando \n");
			sleep(1);
		}
	}
	printf("Terminado\n");
	return 0;
}