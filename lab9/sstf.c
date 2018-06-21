#include <stdio.h>
#include <stdlib.h>
int main(){
      int queue[20],n;//array for storing a disk queue with requests for I/O to blocks on cylinders and its user defined size n
      int head,seek,tseek=0;/*head= in which cylinder our disk head will be initially located,
                             seek=time needed to move the heads to the cylinder containing the desired sector*/
      float aseek;
      int i,j;
      int d[20];
	  printf("queue size: ");
      scanf("%d",&n);
      printf("initial head position: ");
      scanf("%d",&head);
      printf("enter queue:");
      for(i=1;i<=n;i++){
      	scanf("%d",&queue[i]);}
	  queue[0]=head;//we set queue's first element as our head
	  /*here we calculate for each element difference with head as we need to choose
	   the pending request closest to the current head position.*/
      for(j=1;j<=n;j++){
		  d[j]=abs(head-queue[j]);
		}
	  /*then we sort elements of this array and our queue elements in ascending order*/
	  for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(d[i]>d[j]){
				int temp=d[i];
                d[i]=d[j];
                d[j]=temp;
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
      }
      /*then finally print path of head movement with each seek time  as difference of neighbour elements of queue and
      print average seek time as a result of divison of totalseek time to size of queue*/
      for(j=0;j<n;j++){
        seek=abs(queue[j+1]-queue[j]);
        tseek+=seek;
        printf("%d -> %d seek: %d\n",queue[j],queue[j+1],seek);
      }
      aseek=tseek/(float)n;
      printf("average seek time: %f\n",aseek);
      return 0;
    }

