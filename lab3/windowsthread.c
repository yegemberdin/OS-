#include <windows.h>
#include <stdio.h>
int A [2][2] = { {1,2}, {2,1} };
int B [2][2] = { {3,4}, {4,3} };
int C [2][2];
/*structure for passing data to threads:*/
typedef struct {
    int row;
    int column;
}parameters;
DWORD WINAPI *Multiplication(LPVOID* Param){
	parameters *data = Param;
    C[data->row][data->column] = (A[data->row][0] * B[0][data->column])+A[data->row][1] * B[1][data->column];
}
int main(void){
	DWORD ThreadId[4];
	HANDLE ThreadHandle[4];
	int i,j,tid=0;
    for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			parameters *data = (parameters *) malloc(sizeof(parameters));
            data->row= i;
            data->column= j;
			ThreadHandle[tid]= CreateThread (NULL, 0, Multiplication, &data[tid], 0, &ThreadId[tid]);
			tid++;
		}
	}
	if (ThreadHandle[i] != NULL){
	WaitForMultipleObjects(4, ThreadHandle, TRUE, INFINITE);
	printf("\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < 4; i++) {
    CloseHandle(ThreadHandle[i]);
	}
	}

}
