import java.util.Scanner;

public class Max {
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        int x, y;
        System.out.println("Please enter two numbers:");
        x = in.nextInt();
        y = in.nextInt();
        int max;
        max = Math.max(x, y);
        System.out.println(max);
    }
}
