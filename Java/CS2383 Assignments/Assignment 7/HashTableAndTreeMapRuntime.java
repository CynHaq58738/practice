
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;
import java.util.Scanner;
import java.util.TreeMap;

/********************************************************************************************
 * This program calculates the runtime of a Hashtable and a TreeMap.
 * 
 * @Cynthia Haque
 * @date 11-26-2024
 * @version 2024 
 ******************************************************************************************** */
public class HashTableAndTreeMapRuntime 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n;

        System.out.print("Enter a size: ");
        n = sc.nextInt();
        
        ArrayList<Integer> array = new ArrayList<Integer>(n);

        //populate the array
        for(int i=1; i<n; i++)
        {
            array.add(i);
        }

        //randomly shuffle array
        shuffle(array);

        //create a new hashmap using the newHashMap static method
        HashMap<Integer, Integer> hmap = HashMap.newHashMap(n);

        //create a new Treemap
        TreeMap<Integer, Integer> tmap = new TreeMap<Integer, Integer>();

        System.out.println();

        //Runtime of HashMap
        long start = System.currentTimeMillis();
        for(Integer i : array)
        {
            //place key and value into the HashMap with the same object
            hmap.put(i,i);

            //search through the shuffled array using the HashMap
            if(hmap.containsKey(i))
            {
                System.out.println("Element: " + i + " exist at value " + hmap.get(i));
            }
            else
            {
                System.out.println("Element: " + i + " does not exist");
            }
        }
        long end = System.currentTimeMillis();
        

        System.out.println();

        //Runtime of TreeMap
        long start2 = System.currentTimeMillis();
        for(Integer i : array)
        {
            //place key and value into the TreeMap with the same object
            tmap.put(i,i);

            //search through the shuffled array using the TreeMap
            if(tmap.containsKey(i))
            {
                System.out.println("Element: " + i + " exist at value " + tmap.get(i));
            }
            else
            {
                System.out.println("Element: " + i + " does not exist");
            }
        }
        long end2 = System.currentTimeMillis();

        System.out.println("Time to insert and search the Hashmap: " + (end-start) + " millisec");
        System.out.println("Time to insert and search the TreeMap: " + (end2-start2) + " millisec");
    }

    public static void shuffle(ArrayList<Integer> array)
    {
        Random rand = new Random();
        int N = array.size();

        for(int i = 1; i<N; i++)
        {
            int r = i + rand.nextInt(N-i);
            int temp = array.get(i);
            array.set(i, array.get(r));
            array.set(r, temp);
        }  
    }
}
