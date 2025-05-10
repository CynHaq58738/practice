/**********************************************************************************************
 * This program creates an Age class which gets the age of someone and displays how
 * old they are
 *
 * @name Cynthia Haque
 * @date 9-6-2024
 * @version 2024 
 ********************************************************************************************** */
public class Age
{
    protected int age;
    protected String name;

    public Age(int age, String name)
    {
        this.age = age;
        this.name = name; 
    }


    public int getAge()
    {
        return age;
    }

    public String getName()
    {
        return name;
    }

    public void setAge(int age)
    {
        this.age = age;
    }

    public void setName(String name)
    {
        this.name = name;
    }
    
    @Override
    public String toString()
    {
        String output;
        output = getName() + " is " + getAge() +  "yrs old. ";
        return output;
    }
}