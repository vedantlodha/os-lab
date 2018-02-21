#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
int main(){
        int n,i,j,status;
        pid_t pid1,pid2;
        printf("enter the number of string input\n");
        scanf("%d\n",&n);
        char array[n][100];
        for(i=0;i<n;i++)
                scanf("%s\n",&array[i]);

        for(i=0;i<n;i++)
                printf("%s\n",array[i]);
}
