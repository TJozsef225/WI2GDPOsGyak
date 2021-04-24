#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>


void SignalKezelo(int sig) {
    signal(SIGTERM,SIG_IGN);
    printf("\n%d -s szamu jelzest kaptam \n", sig);
    fflush(stdout);
    signal(SIGTERM, SIG_DFL);
    _exit(2);
}

int main(){
    int fd;
    signal(SIGINT, SignalKezelo);
    char szoveg[256];
    mkfifo("fifo_teszt", S_IWUSR| S_IRUSR );

    while(1) {
        scanf("%s", szoveg);
        fd=open("fifo_teszt",O_WRONLY);
        write(fd, szoveg, 12);
        close(fd);
    }
    return 0;
}