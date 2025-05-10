/**********************************************************************************************
 * This program creates a Animal class
 *
 * @name Cynthia Haque
 * @date 7-7-2024
 * @version 2024 
 ********************************************************************************************** */
public class Animal
{
    protected int age;
    protected String name;

    public Animal(int age, String name)
    {
        this.age = age;
        this.name = name;
    }

    public void makeNoise()
    {
        System.out.printf("ROAR! KABOONG! WAHOOO\n");
    }

    public void eat()
    {
        System.out.printf("MUNCH MUNCH MUNCH\n");
    }

}