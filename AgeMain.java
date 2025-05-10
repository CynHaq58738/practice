/**********************************************************************************************
 * This program tests out the Age class
 *
 * @name Cynthia Haque
 * @date 9-6-2024
 * @version 2024 
 ********************************************************************************************** */
public class AgeMain
{
    public static void main(String[] args)
    {
        Age age;

        age = new Age(27, "Josh");
        Age age1 = new Age(28, "Max");

        System.out.println(age.toString());
        System.out.println(age1.toString());



    }
}