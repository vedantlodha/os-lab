#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#define BUFLEN 10
int main(){
        int i;
        char buffer[BUFLEN];
        pid_t pid1;
        pid1=fork();
        if(pid1==0){
                strncpy (buffer,"CHILD\n",BUFLEN);
                buffer[BUFLEN]='\0';
        }
        else if(pid1>0){
                strncpy (buffer,"parent\n",BUFLEN);
                buffer[BUFLEN]='\0';
        }
        else if(pid1==-1){
                printf("error:\n");
                switch(errno){
                        case EAGAIN:
                                printf("cannot fork process:System Process Limited Reached");
                        case ENOMEM:
                                printf("cannot fork process:out of memory");
                           }
                return 1;
        }
        for(i=0;i<5;++i)
        {
                sleep(1);
                write(1,buffer,strlen(buffer));
                printf(buffer);
        }
        return 0;
}

