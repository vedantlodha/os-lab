#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main(int argc,char * argv[]){
        pid_t pid;
        pid=fork();
        char * temp;
        int status;
        
        if(pid==0){
                printf("this is child process\n");
                char *temp;
                for(int i=1;i<argc-1;i++){
                        for(int j=1;j<argc-i-1;j++){
                                if(strcmp(argv[j],argv[j+1])>0){
                                        temp=argv[j];
                                        argv[j]=argv[j+1];
                                        argv[j+1]=temp;

                                }
                        }
                }
                
                for(int i=1;i<argc;i++){
                      //  printf("%s\n",argv[i]);
                        puts(argv[i]);
                }
                        
        }
        else{
                wait(&status);
                printf("this is parent process\n");
                for(int i=1;i<argc;i++)
                printf("%s\n",argv[i]);
        }
 

}
