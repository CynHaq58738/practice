/**********************************************************************************************
 * This program creates tests out the Animal class
 * @name Cynthia Haque
 * @date 7-7-2024
 * @version 2024 
 ********************************************************************************************** */
public class AnimalMain
{
    public static void main(String[] args) 
    {
        Dog myDog = new Dog(34, "Jace", "Ceasar smart");
        System.out.println("Age: " + myDog.age + ", Name: " + myDog.name + ", Food: " + myDog.dogPreferences);
        myDog.eat();
        myDog.makeNoise();

        System.out.println("\n");

        Puppy myPuppy = new Puppy(5, "Alice", "Purina One");
        System.out.println("Age: " + myPuppy.age + ", Name: " + myPuppy.name + ", Food: " + myPuppy.dogPreferences);
        myPuppy.eat();
        myPuppy.makeNoise();
        myPuppy.sleep();
    }
}