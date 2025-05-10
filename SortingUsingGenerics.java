

/**********************************************************************************************
 * This program sorts using generics
 *
 * @name Cynthia Haque
 * @date 9-11-2024
 * @version 2024 
 ********************************************************************************************** */

public class SortingUsingGenerics
{
    public static void main(String[] args) 
    {
        Integer[] arr1 = {1,7,11,3,9,13};

        Character[] arr2 = {'c', 'f', 'a', 'd', 'g', 'e', 'b'};

        Double[] arr3 = {32.22, 56.43, 11.45, 1.32, 89.76, 0.54};

        System.out.println("Sorted Array of Integers: ");
        sortGenerics(arr1);

        System.out.println("Sorted Array of Characters: ");
        sortGenerics(arr2);

        System.out.println("Sorted Array of Doubles: ");
        sortGenerics(arr3);
    }


    public static <T extends Comparable<T>> void sortGenerics(T[] a)
    {
        //Bubble Sort
        for(int i = 0; i< a.length - 1; i++)
        {
            for (int j = 0; j < a.length - i - 1 ; j++) 
            {
                if(a[j].compareTo(a[j+1]) > 0)
                {
                    swap(j, j+1, a);
                }
            }
        }

        //print the array after sorted
        for(T i : a)
        {
            System.out.print(i + ", ");
        }
        System.out.println();

    }

    //swap the array
    public static <T> void swap(int i, int j, T[] a)
    {
        T temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

}
