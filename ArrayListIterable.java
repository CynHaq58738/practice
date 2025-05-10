import java.util.ArrayList;
import java.util.ListIterator;

/**********************************************************************************************
 * This program creates an ArrayList then prints each of the elements out using iterable
 *
 * @name Cynthia Haque
 * @date 9-26-2024
 * @version 2024 
 ********************************************************************************************** */
public class ArrayListIterable 
{
    public static void main(String[] args) 
    {
        ArrayList<Double> myList = new ArrayList<>();
        myList.add(28.9);
        myList.add(68.67);
        myList.add(34.3);
        myList.add(45.8);

        ListIterator<Double> iterableList = myList.listIterator();

        while(iterableList.hasNext())
        {
            Double i = iterableList.next();
            System.out.println(i);
        }
        
    }

}