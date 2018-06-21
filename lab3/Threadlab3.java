package os;

public class Threadlab3 extends Thread {
    public int row,column;
    public int [][] A,B,C;    
    public Threadlab3(int row, int column, int[][] A, int[][] B, int[][] C) {
        this.row = row;
        this.column = column;
        this.A = A;
        this.B = B;
        this.C = C;
    }
    public void run() {
        C[row][column] = (A[row][0]*B[0][column])+ (A[row][1]*B[1][column]) ; 
    }   
}


