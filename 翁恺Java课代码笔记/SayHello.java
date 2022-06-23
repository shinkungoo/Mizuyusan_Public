import java.util.Scanner;

public class SayHello {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int type = in.nextInt();
        switch (type) {
            case 1 -> {
                System.out.println("Hello!");
                System.out.println("Hello!");
            }
            case 2 -> System.out.println("Good morning!");
            case 3 -> System.out.println("Good evening!");
            case 4 -> System.out.println("Goodbye");
            default -> System.out.println("What?");
        }
    }
}
