#include<stdio.h>
struct process{
	int waitingTime,burstTime,remainingTime,completionTime;
       int completed;
};
void swap(int *a, int *b){
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
}
int main(){
        int i,j,ch,timeQuantum,x,y;
        double awt,att;
        struct process p[5];
        printf("Enter the process details:\n");
        for(i=0;i<5;i++){
                printf("enter the burst time for process %d:",i+1);
                scanf("%d",&p[i].burstTime);
                p[i].remainingTime=p[i].burstTime;
        }
        printf("1.Sfj\n2.Round Robin\n3.priority Scheduling(non premptive)\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
                case 1:
                        for(i=0;i<4;i++){
                                for(j=0;j<4-i;j++){
                                if(p[j].burstTime>p[j+1].burstTime){
                                        swap(&p[j].burstTime,&p[j+1].burstTime);
                                        }
                                }
                        }
                        
                        x=0;
                        y=1;
                        for( i=0;i<5;i++){
                                p[i].completionTime=x+p[i].burstTime;
                                x=p[i].completionTime;
                                p[i].waitingTime=p[i].completionTime-p[i].burstTime;
                                awt+=p[i].waitingTime;
                                att+=p[i].waitingTime+p[i].burstTime;
                        }
                        att/=5;
                        awt/=5;
                        printf("Average turnaround time=%f\nAverage waiting time=%f\n",att,awt);
                        break;
                case 2:
                        printf("enter the time quantum:");
                        scanf("%d",&timeQuantum);
                        int q[5];
                        for(i=0;i<5;i++)
                                q[i]=i;
                        int front=0;
                        int rear=4;
                        int time=0;
                        while(!(front==4&&rear==0||rear==front+1)){
                                x=q[front];
                                front=((front+1)%5);
                                if(p[x].remainingTime<=timeQuantum){
                                        time+=p[x].remainingTime;
                                        p[x].completionTime=time;
                                        p[x].remainingTime=0;
                                        p[x].completed=1;
                                }
                                else{
                                        time+=timeQuantum;
                                        rear=(rear+1)%5;
                                        q[rear]=x;
                                        p[x].remainingTime-=timeQuantum;
                                }
                        }
                        x=0;
                        int y=1;
                        for( i=0;i<5;i++){
                                p[i].completionTime=x+p[i].burstTime;
                                x=p[i].completionTime;
                                p[i].waitingTime=p[i].completionTime-p[i].burstTime;
                                awt+=p[i].waitingTime;
                                att+=p[i].waitingTime+p[i].burstTime;
                        }
                        att/=5;
                        awt/=5;
                        printf("Average turnaround time=%f\nAverage waiting time=%f\n",att,awt);
                        break;


        }

}
