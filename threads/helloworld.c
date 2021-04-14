#include <stdio.h>
#include <pthread.h> //hilos
#define NUMTHREADS 10000
int total;
pthread_mutex_t lock;

void *suma(void *datos){
	printf("Hello world desde un hilo %d\n", *(int *)datos);
	//
	pthread_mutex_lock(&lock);
	total += 100;
	pthread_mutex_unlock(&lock);
	//
	pthread_exit(NULL);
}

int main(){
	//pthread_t myThread; Solo un hilo
	pthread_t myThreads[NUMTHREADS]; //arreglo de hilos
	int tIds[NUMTHREADS];
	
	pthread_mutex_init(&lock, NULL);
	pthread_mutex_unlock(&lock); //me aseguro que lo desbloqueo
	
	total = 0;
	
	for(int i = 0; i<NUMTHREADS; i++){
		tIds[i] = i;
		pthread_create(&myThreads[i], NULL, suma, &tIds[i]); // , atributos hilo, funcion, valor que se le pasa a la funcion	
	}
	
	for(int i = 0; i<NUMTHREADS; i++){
		pthread_join(myThreads[i], NULL); //Garantiza que cada hilo haya terminado	
	}
	
	printf("Suma: %d\n", total); //imprime antes de que los hilos terminen
	pthread_exit(NULL); //ultima linea, con esto espera a que todos los hilos ejecuten pthread_exit y terminen. Tambien termina el hilo principal, codigo despues de aqui no se ejectua
}
//gcc -o helloworld helloworld.c -lpthread
