/****************************************************************************************
 * This program tests out the Coin, Stamp, SportCard and the MyCollection Class
 * with generics
 *
 * @name Cynthia Haque
 * @date 9-14-2024
 * @version 2024 
 **************************************************************************************** */
class Asgn1
{
   public static void main(String[] args)
   {
      Coin c1 = new Coin("Canada", "5 cents", 1970, 60, 8.33, 2.50);
      Coin c2 = new Coin("Canada", "25 cents", 1980, 65, 0.30, 0.25);
      Coin c3 = new Coin("Canada", "1 cent", 1920, 30, 6.40, 2.00);
      SportCard s = new SportCard("Sydney Crosby", "hockey", "Pittsburgh Penguins", 8, 5.00, 1.00);
      Stamp st = new Stamp("Canada", "75 cents", 80, 1.50, 1.00);
      
      //collection of coins
      MyCollection coins = new MyCollection<Coin>();
      coins.add(c1);
      coins.add(c2);
      coins.add(c3);

      //collection of stamps
      MyCollection stamp = new MyCollection<Stamp>();
      stamp.add(st);

      //collection of sportcards
      MyCollection sportCard = new MyCollection<SportCard>();
      sportCard.add(s);
      
      //print coins collection
      System.out.println(coins);
      //print the profits
      System.out.println("Sum of profits = " + coins.calculateSumProfits());
      //print the average quality
      System.out.println("Average quality= " + coins.calculateAvgQuality());
      System.out.println();

      //print stamp collection
      System.out.println(stamp);
      //print the profits
      System.out.println("Sum of profits = " + stamp.calculateSumProfits());
      //print the average quality
      System.out.println("Average quality= " + stamp.calculateAvgQuality());
      System.out.println();

      //print spordCard collection
      System.out.println(sportCard);
      //print the profits
      System.out.println("Sum of profits = " + sportCard.calculateSumProfits());
      //print the average quality
      System.out.println("Average quality= " + sportCard.calculateAvgQuality());
      System.out.println();
   }
}
