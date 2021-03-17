// init: The initial user-level program

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *argv[] = { "sh", 0 };

int
main(void)
{
  int pid, wpid;

  if(open("console", O_RDWR) < 0){
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    printf(1, "Iniciando shell\n");
    pid = fork();
    if(pid < 0){
      printf(1, "init: fork failed\n");
      exit();
    }
    if(pid == 0){
	  //Haciendo uso del programa ls, el proceso init padre entra en un loop en el que despues de terminar ls, el proceso hijo de init, vuleve a ejecutar la funcion fork() volviendo a crear un proceso hijo con el programa ls. 
		//Haciendo uso del programa nohayprograma, el proceso init hijo no puede encontrar dicho programa porque no existe, asi que se salta a la siguiente instruccion donde imprime un mensaje de error y se termina, el proceso padra entra en un loop donde empieza a crear procesos hijos que fallaran y se terminaran.
      exec("sh", argv);
      printf(1, "init: exec sh failed\n");
      exit();
    }
    while((wpid=wait()) >= 0 && wpid != pid)
      printf(1, "zombie!\n");
  }
}
