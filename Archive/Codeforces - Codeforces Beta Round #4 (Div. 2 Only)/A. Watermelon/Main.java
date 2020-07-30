import java.util.Scanner;

public class main {
    public static void main(String args[]){
        Scanner scnr = new Scanner(System.in);
        int n = scnr.nextInt();
        if(n%2==0 && n > 2){
            System.out.println("YES");
            return;
        }
        else{
            System.out.println("NO");
        }
    }
}