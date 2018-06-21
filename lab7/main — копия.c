/*TLB*/
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int p;
	int o;
}logicaddress;
logicaddress* log(){
	logicaddress *a = malloc(sizeof(logicaddress));
	a->p=rand()%25+1;
    a->o=rand()%25+1;
    return a;
}
int search_in_pagetable(int p){
	int a;
	FILE *file;
	file=fopen("pagetable.txt", "r");//reads file pagetable.txt and checks whether randomly taken number of logicadress page is equal to one of pages in page table
	while(fscanf(file, "%d", &a)!= EOF){
		if(p==a)
        {
            return p;
        }
	}
    return -1;
	fclose(file);
}

void tlb(int f){//writing page, which was equal to page in pagetable, as new frame to tlb.txt file in order to reach TLB hit
	FILE *file;
	file=fopen("tlb.txt", "a");
	fprintf(file, "%d\n", f);
	fclose(file);
}
int search_in_tlb(int f){
	int p;
	FILE *file;
	file=fopen("tlb.txt", "r");//reads file tlb.txt and checks whether randomly taken number of logicadress page is equal to one of frames in tlb
	while(fscanf(file, "%d", &p) != EOF){
		if(f==p)
        {
            printf("TLB hit\n");
            return p;
        }
	}
	printf("TLB miss\n");
    return -1;
    fclose(file);
}
int main()
{
    while(1){
    	logicaddress *a=log();
        printf("Logical address: %d(page) %d(offset)\n", a->p, a->o);
        int f=search_in_tlb(a->p);
        if(f!=-1){
        	printf("Physical address: %d(frame) %d(offset)\n",f, a->o);
        }
        else{
            f=search_in_pagetable(a->p);
            printf("Physical address: %d(frame) %d(offset)\n",f, a->o);
            tlb(f);
        }
        printf("if you want to exit type 0\n");
        int x;
        scanf("%d", &x);
        if(x==0)
            exit(0);
    }
    return 0;
}
