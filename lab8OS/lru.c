#include<stdio.h>

int main()
{
 int nf, np, frames[10], pages[30], distances[10],faults=0;
 int i, j, temp, flag, found, lastFilledFrame, index, maxdist;
 printf("Enter number of frames:");
 scanf("%d", &nf);
 for(i = 0; i < nf; i++){
      frames[i] = -1;
 }
 lastFilledFrame = -1;
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
    break; // we will break the loop
   }
  }
   
  /* otherwise if flag is still 0,which means that  page is not available in frame, we will replace some page by required page*/
  if(flag == 0) 
  {
   if (lastFilledFrame == nf-1)
   {
    /*here we will calculate distances to past occurance for every frame containing page*/
    for(j = 0; j < nf; j++)
    {
     for(temp = i - 1; temp > -1; temp--) 
     {
      distances[j] = 0; 
      if (frames[j] == pages[temp]) // If that page occurs in the past we will store this didtance in the following array
      {
       distances[j] = i-temp; 
       break;
      }
     } 
    } 
    found = 0;
    /*in the following cases we look for best candidate index for*page replacement in frame*/ 
    for(j = 0; j < nf; j++) // here we just take case when it is not occured in the past, if so we will simply set this frame index to variable index
    {
     if(distances[j] == 0)
     {           
      index = j; 
      found = 1; 
      break;
     }
    }
   }
   else // here we take case when frame is not fully filled,then we set blank frame's index to index variable
   {
     index = ++lastFilledFrame; 
     found = 1; 
   }
   
   //in the last case we will take candidate that is having maximum occurance distance in  the past, for this we just compare distances and take maximum
   if(found == 0)
   {
    maxdist= distances[0];
    index = 0;
    for(j = 1; j<nf; j++) 
    {
     if(maxdist < distances[j])
     {
      maxdist= distances[j];
      index = j; 
     }
    }
   }
   /*so finally we do page replacement and increment number of page faults*/
   frames[index] = pages[i]; 
   faults++; 
  }
  for(j = 0; j < nf; j++)
  {
   if(frames[j] != -1){
       printf("%d\t", frames[j]);
  }
  }
  printf("\n");
 }
 
 printf("\n\nTotal Page Faults = %d", faults); 
    return 0;
}