
import java.util.*;

/**********************************************************************************************
 * This program takes user input for the size of array of integers
 * then calculates the time it takes to sort them using Quick Sort
 *
 * @name Cynthia Haque
 * @date 10-12-2024
 * @version 2024 
 ********************************************************************************************** */
public class QuickSortTime 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        int[] a;
    

        System.out.println("Size of input?: ");
        int size = sc.nextInt();
        a = new int[size];

        for(int i = 0 ; i < size ; i++)
        {
           a[i] = rand.nextInt();  
        }

        long start = System.currentTimeMillis();
        sort(a);
        long end = System.currentTimeMillis();

        System.out.println("\n\nTime to sort the Array: " + (end-start) + " millisec"); 

    }
    public static void sort(int[] a) 
    {
        sort(a, 0, a.length - 1);
    }

    // quicksort the subarray from a[lo] to a[hi]
    private static void sort(int[] a, int lo, int hi) 
    {
        if (hi <= lo) 
            return;
        int j = partition(a, lo, hi);
        sort(a, lo, j-1);
        sort(a, j+1, hi);
    }

    // partition the subarray a[lo..hi] so that a[lo..j-1] <= a[j] <= a[j+1..hi]
    // and return the index j.
    private static int partition(int[] a, int lo, int hi) 
    {
        int i = lo;
        int j = hi + 1;
        int v = a[lo];
        while (true) 
        {

            // find item on lo to swap
            while (a[++i] < v) 
            {
                if (i == hi) break;
            }

            // find item on hi to swap
            while (v < a[--j]) 
            {
                if (j == lo) break;      // redundant since a[lo] acts as sentinel
            }

            // check if pointers cross
            if (i >= j) 
            break;

            exch(a, i, j);
        }

        // put partitioning item v at a[j]
        exch(a, lo, j);

        // now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
        return j;
    }

    // exchange a[i] and a[j]
    private static void exch(int[] a, int i, int j) 
    {
        int swap = a[i];
        a[i] = a[j];
        a[j] = swap;
    }

}
