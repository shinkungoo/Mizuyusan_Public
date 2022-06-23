import java.util.Scanner;

public class Hello {
    public static void main(String[] args){
        double foot;
        double inch;
        Scanner in = new Scanner(System.in);
        foot = in.nextDouble();
        inch = in.nextDouble();
        System.out.println((int)((foot + inch / 12) * 0.3048 * 100) + "cm");
    }
}
