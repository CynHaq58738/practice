
import java.util.*;

/**********************************************************************************************
 * This program takes user input for the size of an array of integers 
 * then calculates the time it takes to sort them using Merge sort
 *
 * @name Cynthia Haque
 * @date 10-12-2024
 * @version 2024 
 ********************************************************************************************** */
public class MergeSortTime 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        int[] a;
        int[] aux;
    

        System.out.println("Size of input?: ");
        int size = sc.nextInt();
        a = new int[size];
        aux = new int[a.length];

        for(int i = 0 ; i < size ; i++)
        {
           a[i] = rand.nextInt();  
        }

        long start = System.currentTimeMillis();
        sort(a);
        long end = System.currentTimeMillis();
        
        System.out.println("\n\nTime to sort the Array: " + (end-start) + " millisec"); 

    }

    private static void merge(int[] a, int[] aux, int lo, int mid, int hi) 
    {

        // copy to aux[]
        for (int k = lo; k <= hi; k++) 
        {
            aux[k] = a[k];
        }

        // merge back to a[]
        int i = lo, j = mid+1;
        for (int k = lo; k <= hi; k++) 
        {
            if(i > mid)
            {
                a[k] = aux[j++];
            }              
            else if (j > hi)
            {
                a[k] = aux[i++];
            }
            else if (aux[j] < aux[i])
            {
                a[k] = aux[j++];
            }
            else
            {
                a[k] = aux[i++];
            }                         
        }

    }

    // mergesort a[lo..hi] using auxiliary array aux[lo..hi]
    private static void sort(int[] a, int[] aux, int lo, int hi) 
    {
        if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        sort(a, aux, lo, mid);
        sort(a, aux, mid + 1, hi);
        merge(a, aux, lo, mid, hi);
    }

    public static void sort(int[] a) 
    {
        int[] aux = new int[a.length];
        sort(a, aux, 0, a.length-1);
    }
    
}
