/*shortest-job-first*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,j;
    int bt[20];
    int wt[20];
    int p[20];
    double twt=0;
    int pos;
    printf("How many processes we have?: ");
    scanf("%d", &n);
    printf("Each bts: ");
    for(i=0; i<n; i++){
        scanf("%d", &bt[i]);//writing each process bt's to array bt[]
        p[i]=i+1;
    }
    for(i=0; i<n; i++){//here in order to have our burst times sorted in ascending order we use the simplest selection sort
    pos=i;
       for(j=i+1; j<n; j++){
           if(bt[j]<bt[pos]){
           pos=j;}}
           int temp=bt[i];
           bt[i]=bt[pos];
           bt[pos]=temp;
           temp=p[i];
           p[i]=p[pos];
           p[pos]=temp;
        }
    wt[0]=0;
    for(i=1; i<n; i++){
    wt[i]=0;
        for(j=0; j<i; j++){
            wt[i]+=bt[j];
        }
        twt+=wt[i];//calculating total waiting time of all processes
    }
    printf("\nGantt chart:");
    printf("\n");
    printf("**********************************************");
    printf("\n");
    for(i=0; i<n; i++){
        printf("--P[%d]",p[i]);}
    printf("--");
    printf("\n********************************************");
    printf("\n");
    for(i=0; i<n; i++){
        printf("--    ");}
    printf("--");
    printf("\n");
    printf("0");
    for(i=0; i<n; i++){
        printf("    %d",wt[i]+bt[i]);}//printing turnaround time for each process
    printf("\n Average waiting time:%f",twt/n);
   }


