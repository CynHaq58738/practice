
import java.util.*;

/**********************************************************************************************
 * This program sorts an array of integers using Selection sort then calculates
 * the time it takes to sort them
 *
 * @name Cynthia Haque
 * @date 9-30-2024
 * @version 2024 
 ********************************************************************************************** */
public class SelectionSortTest 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        int[] A;
    

        System.out.println("Type the number of elements to be added to the list: ");
        int size = sc.nextInt();
        A = new int[size];

        for(int i = 0 ; i < size ; i++)
        {
           A[i] = rand.nextInt();  
        }

        long start = System.currentTimeMillis();
        for(int i = 0; i<size-1; i++)
        {
            int smallest = i;

            for(int j = i+1; j<size; j++)
            {
                if(A[j]< A[smallest])
                {
                    smallest = j;
                }
            }
            int temp = A[i];
            A[i] = A[smallest];
            A[smallest] = temp;
        }
        long end = System.currentTimeMillis();
        //print the array
        for (int i = 0; i < size; i++) 
        {
            System.out.print(A[i] + ",");
        }
        System.out.println("\n\nTime to sort the Array: " + (end-start) + " millisec"); 

    }
}
