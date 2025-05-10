
import java.util.ArrayList;

/**********************************************************************************************
 * This program creates a MyCollection class that uses generics
 *
 * @name Cynthia Haque
 * @date 9-14-2024
 * @version 2024 
 ********************************************************************************************** */
class MyCollection<T> 
{
   // need data structure here to hold the collection...an ArrayList can do
   final ArrayList<T> collection;
   
   public MyCollection()
   {
      collection = new ArrayList<>();
   }
   
   // need a "add" method too...
   public void add(T coll)
   {
      collection.add(coll);
   }
   
   public double calculateSumProfits()
   {
      //create a counter for taking the sum of the profits
      double sum = 0;
      // have code here to call the calcProfit method on each element in the collection
      for(T element : collection)
      {
         // and calculate the sum of those values
         if(element instanceof Coin coin)
         {
            sum += coin.calcProfit();
         }
         else if(element instanceof Stamp stamp)
         {
            sum += stamp.calcProfit();
         }
         else if(element instanceof SportCard sportCard)
         {
            sum += sportCard.calcProfit();
         }
      }
      // return this sum 
      return sum;
   }
   
   public double calculateAvgQuality()
   {
      double avg = 0;
      double sum = 0;
      double count = 0;
      // have code here to call the getQualityLevel method on each element in the collection
      for (T element : collection) 
      {
         // and calculate the average of those values
         if(element instanceof Coin coin)
         {
            sum += coin.getQualityLevel();
         }
         else if(element instanceof Stamp stamp)
         {
            sum += stamp.getQualityLevel();
         }
         else if(element instanceof SportCard sportCard)
         {
            sum += sportCard.getQualityLevel();
         }
         count++;
         avg = sum/count;
      }
      // return this average 
      return avg;
   }
   
   @Override
   public String toString()
   {
      String output = "";
      // have code here to call the toString method on each element in the collection
      for (T element : collection)
      {
         // and separate them with a return character (i.e., "\n")
         if(element instanceof Coin coin)
         {
            output += coin.toString() + "\n";
         }
         else if(element instanceof Stamp stamp)
         {
            output += stamp.toString() + "\n";
         }
         else if(element instanceof SportCard sportCard)
         {
            output += sportCard.toString() + "\n";
         }
      }
      System.out.println("\n");
      // return the string formed 
      return output;
   }
}
