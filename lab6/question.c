#include<stdio.h>
typedef int bool;
#define true 1
#define false 2
void swap(int *a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
}
int sfjScheduler(int rt[],int  at[],int i){
        int min;
        int j,k;
        for(j=0;j<5;j++){
                if(at[j]>=i&&rt[j]!=0){
                        min=j;
                        break;
                }
        }
        for(j=0;j<5;j++){
                if(at[j]<i)
                        continue;
                if(rt[j]==0)
                        continue;
               if(rt[j]<rt[min])
                       min=j;
        }
        return min;
}
int main(){
        bool finish=false;
        int j,i,choice,scheduledProcess;
        double att,awt;
        att=awt=0;
        int arrivalTime[5],burstTime[5],waitTime[5],remainingTime[5],completionTime[5];
        printf("Enter the process details:\n");
        for(i=0;i<5;i++){
                printf("For process %d,enter the following details:\nArrival Time:",(i+1));
                scanf("%d",arrivalTime+i);
                printf("Burst time:");
                scanf("%d",burstTime+i);
        }
        for(i=0;i<4;i++){
                for(j=0;j<4-i;j++){
                        if(arrivalTime[j]>arrivalTime[j+1]){
                                swap(&arrivalTime[j],&arrivalTime[j+1]);
                                swap(&burstTime[j],&burstTime[j+1]);
                        }
                }
        }
        for(i=0;i<5;i++)
                remainingTime[i]=burstTime[i];
        printf("enter your choice:");
        scanf("%d",&choice);
        printf("no fault here\n");
        switch(choice){
                case 1:
                        while(finish)
                        scheduledProcess=sfjScheduler(remainingTime,arrivalTime,i);
                        remainingTime[scheduledProcess]--;
                        if(remainingTime[scheduledProcess]==0)
                                completionTime[scheduledProcess]=i;
                        finish=true;
                        for(j=0;j<5;j++){
                                if(remainingTime[j]!=0){
                                        finish=false;
                                        break;
                                }
                        }
                        printf("finish=%d",finish);
        }
        for(i=0;i<5;i++){
                waitTime[i]=completionTime[i]-arrivalTime[i]-burstTime[i];
        }
        for(int i=0;i<5;i++){
                awt+=waitTime[i];
                att=waitTime[i]+burstTime[i];
        }
        awt/=5;
        att/=5;
        printf("average turnaround time=%f\naverage waiting time=%f",att,awt);
}
