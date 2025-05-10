/**********************************************************************************************
 * This program creates a puppy class
 *
 * @name Cynthia Haque
 * @date 7-7-2024
 * @version 2024 
 ********************************************************************************************** */
public class Puppy extends Dog
{

    public Puppy(int age, String name, String dogPreferences)
    {
        super(age, name, dogPreferences); 
    }
 
    @Override
    public void makeNoise()
    {
       System.out.printf("WOOF WOOF WOOF\n");
    }

    @Override
    public void eat()
    {
        super.eat();
    }

    public void sleep()
    {
        System.out.printf("zzzzzzzz\n");
    }
}