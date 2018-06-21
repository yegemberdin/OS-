#include <stdio.h>
#include <stdlib.h>
int main(){
      int queue[20],n;//array for storing a disk queue with requests for I/O to blocks on cylinders and its user defined size n
      int head,seek,tseek=0;/*head= in which cylinder our disk head will be initially located,
                             seek=time needed to move the heads to the cylinder containing the desired sector*/
      float aseek;
      int i,j;
      int big[20],b=0, small[20],s=0;/*here we store queue elements that are bigger/smaller than our head with their size s and b*/
      int max;//also we have to know max element
      printf("queue size: ");
      scanf("%d",&n);
      printf("initial head position: ");
      scanf("%d",&head);
      printf("enter queue:");
      for(i=1;i<=n;i++){
            scanf("%d",&queue[i]);}
      printf("max: ");
      scanf("%d",&max);
      for(i=1;i<=n;i++){/*here we compare our queue elements with head and from a result store them to corresponding arrays*/
            if(queue[i]>=head){
                  big[b]=queue[i];
                  b++;// each time we increment size of our array dynamically
            }
            else{
                  small[s]=queue[i];
                  s++;
          }
      }
      /*then we sort elements of each array: both in ascending order*/
      for(i=0;i<s-1;i++){
            for(j=i+1;j<s;j++){
                  if(small[i]>small[j]){
                        int temp=small[i];
                        small[i]=small[j];
                        small[j]=temp;
                  }
            }
      }
      for(i=0;i<b-1;i++){
            for(j=i+1;j<b;j++){
                  if(big[i]>big[j]){
                        int temp=big[i];
                        big[i]=big[j];
                        big[j]=temp;
                  }
            }
      }
      /*so as our queue will be sorted we set its first element as our head
      and followingly we reassign to our userdefined queue array firstly with our new sorted big[] array till max and it goes to 0 ,
      then our small[]array*/
      queue[0]=head;
      for(i=1,j=0;j<b;i++,j++)
            queue[i]=big[j];
        queue[i]=max;
        queue[i+1]=0;
        for(i=b+3,j=0;j<s;i++,j++)
            queue[i]=small[j];
    /*then finally print path of head movement with each seek time  as difference of neighbour elements of queue and
    print average seek time as a result of divison of totalseek time to size of queue*/
      for(j=0;j<=n+1;j++){
            seek=abs(queue[j+1]-queue[j]);
            tseek+=seek;
            printf("%d -> %d seek: %d\n",queue[j],queue[j+1],seek);
      }
      aseek=tseek/(float)n;
      printf("average seek time: %f\n",aseek);
      return 0;
}
