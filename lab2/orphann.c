#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <wait.h>

int main()
{
    pid_t pid;
    pid=fork();
    if(pid>0){
        fprintf(stderr,"Parent pid is %d\n", getpid());
        exit(0);
    }
    else if(pid==0){
        sleep(5);
        fprintf(stderr,"Child pid is %d\n", getpid());
        system("ps -o pid,ppid,stat,cmd");
    }
    else{
        perror("Error");
        exit(0);
    }
    return 0;
}
