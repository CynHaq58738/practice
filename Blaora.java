import java.util.Scanner;

public class Blaora
{
    public static void main(String[] args) 
    {
        //Declaration & Intialization 
        Scanner sc = new Scanner(System.in);
        //distance
        double d;
        //velocity
        int v;
        //time
        int t;
        //acceleration
        int a;

        System.out.println("Enter an integer that is greater than or equal to -1000 and less than or equal to 1000: ");
        v = sc.nextInt();
        
        System.out.println("Enter an integer that is greater than or equal to -1000 and less than or equal to 1000: ");
        t = sc.nextInt();

        System.out.println("Enter an integer that is greater than or equal to 0 and less than or equal to 1000: ");
        a = sc.nextInt();

        //Calculation
        d = (v*t) + (0.5 * (a*(Math.pow(t,2))));

        //Output
        System.out.format("The answer is %.9f",d);

    }
}