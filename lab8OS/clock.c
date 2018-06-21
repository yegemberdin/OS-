#include<stdio.h>

int main()
{
 int nf, np, frames[10], pages[30],faults=0;
 int i, j, flag,usebit[10];
 printf("Enter number of frames:");
 scanf("%d", &nf);
 for(i = 0; i < nf; i++){
      frames[i] = -1;
 }
 printf("Enter number of pages: ");
 scanf("%d", &np);
 printf("Enter page reference string: ");
 for(i = 0; i < np; ++i){
        scanf("%d", &pages[i]);
    }
 
 /*here we check whether page is in frame already, if so we set flag to 1 which shows that page is available in frame*/
 for(i = 0; i < np; i++)
 {
  flag = 0; 
  for(j = 0; j < nf; j++) 
  {
   if(frames[j] == pages[i]) 
   {
    flag = 1; 
    usebit[j]=1;
    break; // we will break the loop
   }
  }
   
  /* otherwise if flag is still 0,which means that  page is not available in frame, we will replace some page by required page*/
  if(flag == 0) 
  {
   for(j=0;j<nf;j++)
   {
    if(usebit[j]==0)
    {
     frames[j]=pages[i];
     usebit[j]=1;
     flag=1;
     faults++;
     break;
    }
   }
  }
  if(flag==0)
  {
   for(j=0;j<nf;j++)
   usebit[j]=0;
   faults++;
  }
  frames[0]=pages[i];
  usebit[0]=1;
  
  
 } 
 printf("\n\nTotal Page Faults = %d", faults); 
 return 0;
} 
