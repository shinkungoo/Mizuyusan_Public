import java.util.Scanner;

public class CalculateAverage {
    public static void main(String[] args){
        Scanner in  = new Scanner(System.in);
        int number, sum = 0, count = 0;
        number = in.nextInt();
        while(number != -1){
            sum += number;
            count += 1;
            number = in.nextInt();
        }
        if(count > 0){
            System.out.println("average = " + (double)sum / count);
        }
    }
}
