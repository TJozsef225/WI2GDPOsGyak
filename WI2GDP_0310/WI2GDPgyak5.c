#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int pid;
    int status;

    if ((pid = fork()) < 0) {
        perror("Hiba a forkban");
    }
    else if (pid == 0) exit(7);

    if(wait(&status)!=pid)
        perror("Hiba a wait-el");
    if(WIFEXITED(status))
        printf("Sikeres");

    return 0;
}