#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>


void handle_sigint(int sig)
{
    signal(SIGTERM,SIG_IGN);
    printf("%d jelzest kaptam\n", sig);
    _exit(2);
}

int main()
{
    signal(SIGINT, handle_sigint);
    char s[1024];
    int fd;
    int sorszam = 1;
    while(1) {
        fd=open("fifo_teszt",O_RDONLY);
        if(fd == -1) {
            printf("Fajl nem letezik.\n");
            return 1;
        }
        else {
            read(fd,s,sizeof(s));
            printf("%d. %s\n",sorszam, s);
            close(fd);
            sorszam++;
        }
    }
    return 0;
}