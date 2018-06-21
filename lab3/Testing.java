package os;

public class Testing {
    public static int [][] A = {{1,2}, {2,1}}; 
    public static int [][] B = {{3,4}, {4,3}}; 
    public static int [][] C = new int [2][2];
    public static Threadlab3 [][] thrd = new Threadlab3[3][3];
    public static void main(String[] args) throws InterruptedException {      
        for (int i = 0; i<2; i++){
            for (int j=0; j<2; j++){
                thrd[i][j] = new Threadlab3(i,j,A,B,C);
                thrd[i][j].start();
                thrd[i][j].join();
            }
        }        
        for (int i = 0; i<2; i++){
            for (int j=0; j<2; j++){
                System.out.print(C[i][j]+" ");
            }
            System.out.println(" ");
        }  
    }
}
