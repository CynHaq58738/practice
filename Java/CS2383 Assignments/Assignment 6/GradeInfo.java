
import java.util.Scanner;
import java.util.TreeMap;

/********************************************************************************************
 * This program takes a list of marks as percentages, returns the corresponding 
 * letter grade for each, and calculate an average GPA for that list. 
 *
 * @Cynthia Haque
 * @date 11-21-2024
 * @version 2024 
 ******************************************************************************************** */
public class GradeInfo
{
    //create a static class
    public static class GradeDetails
    {
        private String letterGrade;
        private double gpa;
        private int minPercentage;

        public GradeDetails(String letterGrade, double gpa, int minPercentage)
        {
            this.letterGrade = letterGrade;
            this.gpa = gpa;
            this.minPercentage = minPercentage;
        }

        public String getLetterGrade()
        {
            return letterGrade;
        }

        public double getGpa()
        {
            return gpa;
        }

    }

    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        TreeMap<Integer, GradeDetails> gradeSchema = new TreeMap<Integer, GradeDetails>();
        String[] percentages;

        setGradeInfo(gradeSchema);

        System.out.println("Give the list of percentages (separated by spaces):");
        percentages = sc.nextLine().split(" ");

        computeList(percentages, gradeSchema);
    }
    
    //Method to set up the grade information
    public static void setGradeInfo(TreeMap<Integer, GradeDetails> gradeSchema)
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Min Percentage for an A+:");
        gradeSchema.put(sc.nextInt(), new GradeDetails("A+", 4.3, 90));

        System.out.print("Min Percentage for an A:");
        gradeSchema.put(sc.nextInt(), new GradeDetails("A", 4.0, 85));

        System.out.print("Min Percentage for an A-:");
        gradeSchema.put(sc.nextInt(), new GradeDetails("A-", 3.7, 80));
        
        System.out.print("Min Percentage for an B+:");
        gradeSchema.put(sc.nextInt(), new GradeDetails("B+", 3.3, 75));
      
        System.out.print("Min Percentage for an B:");
        gradeSchema.put(sc.nextInt(), new GradeDetails("B", 3.0, 70));

        System.out.print("Min Percentage for an B-:");
        gradeSchema.put(sc.nextInt(), new GradeDetails("B-", 2.7, 65));

        System.out.print("Min Percentage for an C+:");
        gradeSchema.put(sc.nextInt(), new GradeDetails("C+", 2.3, 58));
        
        System.out.print("Min Percentage for an C:");
        gradeSchema.put(sc.nextInt(), new GradeDetails("C", 2.0, 50));

        System.out.print("Min Percentage for an D:");
        gradeSchema.put(sc.nextInt(), new GradeDetails("D", 1.7, 45));
        
        System.out.print("Min Percentage for an F:");
        gradeSchema.put(sc.nextInt(), new GradeDetails("F", 0.0, 0));
    }

    //Method to compute the list of percentages
    public static void computeList(String[] percentages, TreeMap<Integer, GradeDetails> gradeSchema)
    {
        int count = 0;
        double totalGpa = 0;

        System.out.println("The corresponding letter grades are: ");
        //for each string per in percentages
        for(String per : percentages)
        {
            //convert the string into an integer
            int percent = Integer.parseInt(per);
            //compare the percentages to the grade schema and get the corresponding value
            GradeDetails grInfo = gradeSchema.floorEntry(percent).getValue();
            System.out.print(grInfo.getLetterGrade() + "  ");

            //count the number of elements
            count++;
            //add the total gpa
            totalGpa += grInfo.getGpa();
            
        }
        double avgGpa = totalGpa/count;
        System.out.println("\nAnd the average GPA is: " + avgGpa);
    }
    

}

 