import java.io.*;
import java.util.ArrayList;

/***********************************************************************
 * SaveRead file.
 * 
 * @Jeremy Qiao
 * @Jeremy Qiao
 * @date 11-26-2024
 * @version projectSubmission7**
*********************************************************************** */

public class SaveRead implements Serializable
{
    // Save method to serialize the data
    public static void save(ArrayList<Group> groups) 
    {
        try (FileOutputStream fos = new FileOutputStream("listSchedule.dat");
             ObjectOutputStream outfile = new ObjectOutputStream(fos)) 
             {

            // Write the list of groups to the file
            outfile.writeObject(groups);
            System.out.println("Data successfully saved to listSchedule.dat.");

        } 
        catch (IOException e) 
        {
            System.out.println("Problem saving the file: " + e.getMessage());
        }
    }

    // Read method to deserialize the data
    public static ArrayList<Group> read() 
    {
        ArrayList<Group> newList = new ArrayList<>();

        try (FileInputStream fis = new FileInputStream("listSchedule.dat");
             ObjectInputStream infile = new ObjectInputStream(fis)) 
             {

            // Read the list of groups from the file
            newList = (ArrayList<Group>) infile.readObject();
            System.out.println("Data successfully loaded from listSchedule.dat.");

        } 
        catch (FileNotFoundException e) 
        {
            System.out.println("Cannot find the file: " + e.getMessage());
        } 
        catch (IOException e) 
        {
            System.out.println("Problem reading the file: " + e.getMessage());
        } 
        catch (ClassNotFoundException e) 
        {
            System.out.println("Problem parsing the file: " + e.getMessage());
        }

        return newList;
    }
}