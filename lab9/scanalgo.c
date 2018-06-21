#include <stdio.h>
#include <stdlib.h>
int main(){
	int queue[20],n;//array for storing a disk queue with requests for I/O to blocks on cylinders and its user defined size n 
	int head,seek,tseek=0;/*head= in which cylinder our disk head will be initially located, 
	                       seek=time needed to move the heads to the cylinder containing the desired sector*/
	float aseek;
	int i,j;
	int big[20],b=0, small[20],s=0;/*here we store queue elements that are bigger/smaller than our head with their size s and b*/
	printf("queue size: ");
	scanf("%d",&n);
	printf("initial head position: ");
	scanf("%d",&head);
	printf("enter queue:");
	for(i=1;i<=n;i++){
		scanf("%d",&queue[i]);}
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
	/*then we sort elements of each array: small[]array in descending, big[] array in ascending order*/
	for(i=0;i<s-1;i++){
		for(j=i+1;j<s;j++){
			if(small[i]<small[j]){
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
	and followingly we reassign to our userdefined queue array firstly with our new sorted small[] array and it goes to zero,
	then our big[]array*/
    queue[0]=head;
	for(i=1,j=0;j<s;i++,j++)
		queue[i]=small[j];
        queue[i]=0;
        for(i=s+2,j=0;j<b;i++,j++)
        	queue[i]=big[j];
    /*then finally print path of head movement with each seek time  as difference of neighbour elements of queue and 
    print average seek time as a result of divison of totalseek time to size of queue*/   
	for(j=0;j<=n;j++){
		seek=abs(queue[j+1]-queue[j]);
		tseek+=seek;
		printf("%d -> %d seek: %d\n",queue[j],queue[j+1],seek);
	}
    aseek=tseek/(float)n;
	printf("average seek time: %f\n",aseek);
	return 0;
}
