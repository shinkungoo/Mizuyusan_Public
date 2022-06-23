import java.util.Scanner;

public class ReverseNumber {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int number = in.nextInt();
        do{
            int digit = number % 10;
            System.out.print(digit);
            number /= 10;
        }while(number > 0);
        System.out.println();
    }
}
