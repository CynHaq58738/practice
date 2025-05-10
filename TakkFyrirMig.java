import java.util.Scanner;

public class TakkFyrirMig
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        //Number of guests
        int n;
        String guestNames;

        System.out.println("Enter a number for the number of guests: ");
        n = sc.nextInt();

        //Consume newLine
        sc.nextLine();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter a name for a guest:\n ");
            guestNames = sc.nextLine();
            System.out.println("Takk " + guestNames);
        }
    }
} 