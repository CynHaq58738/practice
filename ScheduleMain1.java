import java.util.ArrayList;
import java.util.Scanner;

/**********************************************************************************************
 * This program creates courses and put them in specified groups
 *
 * @name Cynthia Haque and Jeremy Qiao
 * @date 11-3-2024
 * @version 2024 
 ******************************************************************************************** */
public class ScheduleMain1 
{
    public static void main(String[] args) 
    {
        
        Scanner scanner = new Scanner(System.in);
        ArrayList<Course<String>> courseList = new ArrayList<>();
        
        //client specifies the name for the group of courses
        System.out.print("Enter group name: ");
        String groupName = scanner.nextLine();

        String response;
        do
        {
            System.out.print("\nEnter course ID: ");
            String courseID = scanner.nextLine();

            System.out.print("Enter extra text: ");
            String extraText = scanner.nextLine();

            System.out.print("Enter instructor's name: ");
            String instructor = scanner.nextLine();

            System.out.print("Enter course schedule(timeslot): ");
            String courseSchedule = scanner.nextLine();

            // using generic and insert those four attributes inside newCourse object
            Course<String> newCourse = new Course<>(courseID, extraText, instructor, courseSchedule);
            courseList.add(newCourse);
            
            System.out.println("\nCourse Info:");
            System.out.println(newCourse.toString());
            
            System.out.print("\nDo you want to add another course? (yes/no): ");
            response = scanner.nextLine();

        }while(response.equals("yes"));

        //Display the group name
        System.out.println("\n" + groupName + ": ");
        //for each course in the courseList
        for(Course<String> course: courseList)
        {
         //Display the courses that are specified for the group name
           System.out.println(course.getCourseID());
        }

    }
}