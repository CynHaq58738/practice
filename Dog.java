/**********************************************************************************************
 * This program creates a Dog class
 *
 * @name Cynthia Haque
 * @date 7-7-2024
 * @version 2024 
 ********************************************************************************************** */
public class Dog extends Animal
{
    protected String dogPreferences;

    public Dog(int age, String name, String dogPreferences)
    {
        super(age, name);
        this.dogPreferences = dogPreferences;
    }

    @Override
    public void makeNoise()
    {
       System.out.printf("RUFF RUFF RUFF\n");
    }

    @Override
    public void eat()
    {
        super.eat();
    }
}