
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

int main(void)
{
    int pipefds[2];
    int buffer;
        
    if(pipe(pipefds)== -1)
    {
        perror("pipe");
        exit (EXIT_FAILURE);
    }
    
    int number, flag=0;
    {
        
        printf("Enter a postive integer to check prime:");
        scanf("%d", &number);
         write (pipefds[1], &number, sizeof(number));
    }  
        for (int i= 2; i<=number / 2; i++)
        {
            if (number % i == 0)
            {
                flag = 1;
                break;
            }
        }
            if (number == 1)
            {
                printf (" 1 is neither prime or nor composite.\n");
            }
            else
            {
                if (flag == 0)
                printf ("%d is a prime number.\n" , number);
                else
                printf ("%d is not a prime number.\n" , number);
        
            }
            read (pipefds[0], &buffer, sizeof(buffer));
            close(pipefds[0]);

         printf("TO EXIT PLEASE ENTER (ctrl+c)\n");
         sleep(60);
         printf("EXIT");

 return EXIT_SUCCESS;
 }

