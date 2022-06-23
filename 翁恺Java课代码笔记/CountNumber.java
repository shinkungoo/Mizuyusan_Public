import java.util.Scanner;

public class CountNumber {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        int digit = 0;
        if(num < 0){
            num *= -1;
        }
        do {
            digit += 1;
            num /= 10;
        }while(num > 0);


        System.out.println(digit);
    }
}
