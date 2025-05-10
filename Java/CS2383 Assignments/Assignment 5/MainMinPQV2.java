import java.util.Arrays;
import java.util.Scanner;

/**********************************************************************************************
 * This program tests out the minimum priority queue class
 *
 * @name Cynthia Haque
 * @date 10-31-2024
 * @version 2024 
 ********************************************************************************************** */
public class MainMinPQV2
{
    public static void main(String[] args) 
    {
        //intialization & declaration
        Scanner sc = new Scanner(System.in);
        int m;
        String input;
        int[] pq;

        //ask user for a value for m
        System.out.print("Enter a value for m: ");
        m = sc.nextInt();

        //set the PQ to that size
        MinPQ<Integer> minPQ = new MinPQ<Integer>(m+1);
        pq = new int[m];

        //consume new line to get rid of garbadge character
        sc.nextLine();

        //ask user for a sequence of integers
        System.out.println("Enter a sequence of integers separated by space: ");
        input = sc.nextLine();

        //create scanner to read in the integers
        Scanner scanIn = new Scanner(input);

        //extract each integer one at a time
        while(scanIn.hasNextInt())
        {
            int value = scanIn.nextInt();
            /******************************************************
             *  Each time an integer is extracted, immediately 
             *  perform the operations with the priority queue 
             *  so that only the m largest elements are kept 
             ****************************************************** */
        
            //insert elements
            minPQ.insert(value);  
           
            //if the number of sequences exceeds the value of m
            if(minPQ.size()>m)
            {
                //remove the min
                minPQ.delMin();
            }

            
        }

        //transfer minPQ elements to pq
        int index = 0;
        while(!minPQ.isEmpty() && index <= m)
        {
            pq[index++] = minPQ.delMin();
        }
    
        //print out the largest m elements
        System.out.println("The m largest elements: ");
        System.out.println(Arrays.toString(pq));  

        //Ask user to delete an index of the pq
        System.out.println("Enter an index to be deleted: ");
        int elem = sc.nextInt();

        //delete the element
        minPQ.DeleteElement(elem);

        //print out the largest m elements
        System.out.println("The m largest elements: ");
        System.out.println(Arrays.toString(pq));  
    }
    
}
