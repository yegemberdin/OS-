/*round-robbin*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,j;
    int bt[20];
    int wt=0;
    int p[20];
    int ar[20];
    int rt[20];
    double twt=0;
    int pos;
    int r;
    int flag=0,quantum,time;
    printf("How many processes we have?: ");
    scanf("%d", &n);
    r=n;
    printf("Each bts and arrival time: ");
    for(i=0; i<n; i++){
        scanf("%d", &bt[i]);//writing each process bt's to array bt[]
        scanf("%d", &ar[i]);//writing each process arrival time to array ar[]
        rt[i]=bt[i];//array where we store remaining time of each process
    }
    printf("time quantum: ");
    scanf("%d", &quantum);
    for(time=0,i=0;r!=0;){
    if(rt[i]<=quantum &&rt[i]>0){//here we check whether remaining time is less than quantum if so,we print our Gantt chart and decrement remainig time
    time+=rt[i];
    rt[i]=0;
    flag=1;
    }
    else if(rt[i]>0){
    rt[i]-=quantum;
    time+=quantum;
    }
    if(rt[i]==0 && flag==1){
    r--;
    printf("P[%d]\t--\t%d\n",i+1,time-ar[i]);
    wt+=time-ar[i]-bt[i];
    flag=0;
    }
    if(i==n-1){i=0;}
    else if(ar[i+1]<=time){
    i++;}
    else i=0;

    }
    printf("\n Average waiting time:%f",wt/n);
   }

