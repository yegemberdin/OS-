#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int A [2][2] = { {1,2}, {2,1} };
int B [2][2] = { {3,4}, {4,3} };
int C [2][2];
/* our 4 threads will call this function: */
void *runner(void *param);
/*structure for passing data to threads:*/
typedef struct {
    int row;
    int column;
}parameters;

int main(int argc, char *argv[]) {
    int i,j;
    /*within in loop it can create 4 threads:*/
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            parameters *data = (parameters *) malloc(sizeof(parameters));
            data->row= i;
            data->column= j;
            pthread_t tid;
            pthread_attr_t attr;
            pthread_attr_init(&attr);
            pthread_create(&tid,&attr,runner,data);
            pthread_join(tid, NULL);
        }
    }
    printf("\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}
void *runner(void *param) {
    parameters *data = param;
    C[data->row][data->column] = (A[data->row][0] * B[0][data->column])+A[data->row][1] * B[1][data->column];
    pthread_exit(0);
}
