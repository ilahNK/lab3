#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>


void sighup(); 
void sigint();
void sigquit();

int main(void)
{
 int pid;

  
   if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    
   if (pid == 0)
     {
       signal(SIGHUP,sighup); /* set function calls */
       signal(SIGINT,sigint);
       signal(SIGQUIT, sigquit);
       for(;;);
     }
  else 
     {
       printf("\nPARENT: sending SIGHUP\n\n");
       kill(pid,SIGHUP);
     
       printf("\nPARENT: sending SIGINT\n\n");
       kill(pid,SIGINT);
       
       printf("\nPARENT: sending SIGQUIT\n\n");
       kill(pid,SIGQUIT);
  
     }
return 0;
}

void sighup()

{  signal(SIGHUP,sighup);
   printf("CHILD:This is a special signal handler for SIGHUP\n");
}

void sigint()

{  signal(SIGINT,sigint); 
   printf("CHILD:This is a special signal handler for SIGINT\n");
}

void sigquit()

{ printf("Hahaha This is a special signal handler for SIGGUIT\n");
  exit(0);
}


