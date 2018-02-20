#include<stdio.h>
int main(){
        int temp;
        int a[]={22,11,2,4,55,3};
        for(int i=1;i<5;i++){
                for (int j=0;j<5-i;j++){
                       if(a[j]<a[j+1]){
                               temp=a[j];
                               a[j]=a[j+1];
                               a[j+1]=temp;
                       }
                }
        }
        for(int i=0;i<6;i++)
               printf("%d\n",a[i]);
}

