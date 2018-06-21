/*Banker's algorithm*/
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 3
int main()
{
    int available[NUMBER_OF_RESOURCES];
    int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
    int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
    int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
    int output[NUMBER_OF_RESOURCES];
    int executed[NUMBER_OF_CUSTOMERS];
    int i,j,count=0;
    int all[5]={0};/*this will be massive for storing all our resource instances*/
    for(i = 0; i< NUMBER_OF_CUSTOMERS; i++)
        executed[i] = 0;/*initializing each customer's execution to 0*/
    printf("Enter Maximum Table:\n");
    for(i = 0; i < NUMBER_OF_CUSTOMERS; i++){
        for(j = 0; j < NUMBER_OF_RESOURCES; j++)
            scanf("%d", &maximum[i][j]);
    }
    printf("Enter Allocation Table:\n");
    for(i = 0; i < NUMBER_OF_CUSTOMERS; i++){
        for(j = 0; j < NUMBER_OF_RESOURCES; j++)
            scanf("%d", &allocation[i][j]);
    }
    for(i = 0; i < NUMBER_OF_CUSTOMERS; i++){
        for(j = 0; j < NUMBER_OF_RESOURCES; j++)
            all[j]+=allocation[i][j];
    }
    printf("Enter Available Resources : ");
    for(j = 0; j < NUMBER_OF_RESOURCES; j++){
        scanf("%d", &available[j]);
        all[j]+=available[j];
    }
    for(i = 0; i < NUMBER_OF_CUSTOMERS; i++){
        for(j = 0; j < NUMBER_OF_RESOURCES; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];/*here we calculate needed resource of each type for each process*/
    }
    for(i = 0; i < NUMBER_OF_CUSTOMERS; i++){/*here we check whether our all resource instances of each type is bigger than each process maximum*/
        for(j = 0; j < NUMBER_OF_RESOURCES; j++)
            if(all[j]<maximum[i][j])
                printf("The system is in an unsafe state");
                break;
    }
        do
        {
            for(i = 0; i < NUMBER_OF_CUSTOMERS; i++)
            {
                if(executed[i] == 0)
                {
                    for(j = 0; j < NUMBER_OF_RESOURCES; j++)/*in this loop we check whether available resource instances are
                                                             bigger than needed, if so, for output safe sequence massive we write number of process
                                                              then to available resources we add its preciously allocated resources as this process will be
                                                              executed */
                    {
                        if(available[j] >= need[i][j])
                        {
                            output[count] = i;
                            count++;
                            available[j] += allocation[i][j];
                            maximum[i][j] = 0;
                            allocation[i][j] = 0;
                            executed[i] = 1;
                        }
                            break;
                    }
                }
            }
        }
        while(count != NUMBER_OF_CUSTOMERS);/*it will be done untill all processes will be executed*/

        if(count == NUMBER_OF_CUSTOMERS)
        {
            printf("\nThe system is in a safe state\n");
            printf("Safe Sequence : <");
            for( i = 0; i < NUMBER_OF_CUSTOMERS; i++)
                printf("Customer[%d] ", output[i]);/*we print safe sequence as we previously were saving each process number to
                                                  this massive as they were executed*/
            printf(">\n");
        }
        else
            printf("\nThe system is in an unsafe state");

}
