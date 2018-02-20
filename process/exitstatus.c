#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
        int status;
        pid_t pid;
        pid=fork();
        if(pid==0){
                printf("im child process with pid:%d\n",getpid());
                while(1);
                exit(0);
        }
        else{
                wait(&status);
                printf("\n im the parent process\n");
                        printf("\n the child process returned%d\n",WIFEXITED(status));
        }
}
