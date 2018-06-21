/*first-come-first-served*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,j;
    int bt[20];
    int wt[20];
    double twt=0;
    printf("How many processes we have?: ");
    scanf("%d", &n);
    printf("Each bts: ");
    for(i=0; i<n; i++){
        scanf("%d", &bt[i]);//writing each process bt's to array bt[]
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
    for(i=1; i<n+1; i++){
        printf("--P[%d]",i);}
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
