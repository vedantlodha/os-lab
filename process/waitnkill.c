#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
       
        int status;
        pid_t pid;
        printf("this is parent process\n");
        pid=fork();
        if(pid==0){
                printf("\n child pid=%d\n",getpid());
                printf("child process running\n");
                while(1){
                        continue;
                }
        }
        if(pid>0){
                wait(&status);
                printf("this is parent back and child has been killed.\n");
        }
}
