import java.util.Scanner;

public class GuessNumber {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int number = (int)(Math.random() * 100 + 1);
        int a;
        int count = 0;
        do{
            a = in.nextInt();
            count += 1;
            if(a > number){
                System.out.println("Too big");
            }else if(a < number){
                System.out.println("Too small");
            }
        }while(a != number);
        System.out.println("You have guessed " + count + " time(s)");
    }
}
