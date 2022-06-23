import java.util.Scanner;

public class TicketSeller {
    public static void main(String[] args){
        // initialization
        Scanner in = new Scanner(System.in);
        int balance = 0;
        while(true){
            System.out.println("Please drop coin");
            int amount = in.nextInt();
            balance += amount;
            // print ticket
            if(balance >= 10){
                System.out.println("*************************");
                System.out.println("*Java High Speed Railway*");
                System.out.println("*    Undecided Seat     *");
                System.out.println("*        10 yuan        *");
                System.out.println("*************************");
                // calculate change
                System.out.println("Change:" + (balance - 10));
                balance -= 10;
            }else{
                System.out.println("Not enough");
            }
        }
    }
}
