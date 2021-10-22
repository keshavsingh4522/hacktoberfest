import java.util.Scanner;
public class Transpose {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the no.of rows and columns\n");
		int r= sc.nextInt();
		int c= sc.nextInt();
		int matrix[][]= new int[r][c];
		System.out.println("Enter the elements of matrix\n");
		for(int i=0; i<r; i++){
			for(int j=0; j<r; j++){
				matrix[i][j] = sc.nextInt();
			}
		}
		System.out.println("The matrix is	 :");
		for(int i=0; i<r; i++){
			for(int j=0; j<r; j++){
				System.out.print(matrix[i][j]+"\t");
			}
		System.out.print("\n");}
		System.out.print("Transpose of the matrix is\n");		for(int i=0; i<c; i++){
			System.out.print("\n");
			for(int j=0; j<r; j++){
				System.out.print(matrix[j][i]+"\t");
			}
		}
	}
}