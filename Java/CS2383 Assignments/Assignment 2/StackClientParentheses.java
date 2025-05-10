
import java.util.Scanner;

/****************************************************************************************
 * This program checks if the parentheses are balanced
 *
 * @name Cynthia Haque
 * @date 9-23-2024
 * @version 2024 
 **************************************************************************************** */
public class StackClientParentheses 
{
    public static void main(String[] args) 
    {
        LinkedStack stack = new LinkedStack();
        Scanner sc = new Scanner(System.in);
        String input;
        char[] array;
        int index = 0;

        //Read in input from the user for strings to be pushed onto the the stack
        System.out.println("Enter some characters:\n ");
        input = sc.nextLine();

        //convert strings to an array of characters
        array = stringToChar(input);

        for(char c : array)
        {
            //increment the index
            index++;
            if(c == '(' || c == '[' || c == '{')
            {
                //push individual characters onto stack as string
                stack.push(String.valueOf(c));
            }
            else if( c == ')' || c == ']' || c == '}')
            {
                //checks if the stack is empty
                if(stack.isEmpty())
                {
                    System.err.println("Unbalenced parenthesis found: " + c + " at " + index);
                    return;
                }

                String top = stack.pop();
                //checks if the top of the stack matches the corresponding opening parenthesis
                if((c == ')') && (!"(".equals(top)) || (c == ']') && (!"[".equals(top)) || (c == '}') && (!"{".equals(top)))
                {
                    System.err.println("Unbalenced parenthesis found: " + c + " at " + index);
                    return;
                }   
            }  
        }

        //if the stack is not empty
        if(!stack.isEmpty())
        {
            //then the stack is not balanced as there are unmatched open parentheses 
            System.out.println("false");
        }
        else
        {
            //there are no unmatched open parentheses, therfore it is balanced
            System.out.println("true");
        }
         
    }

    /*************************************************************************************************
     * Function 1 :       creates a function called stringToChar()
     *
     * Purpose:           To convert strings into an array of characters
     *
     * Input:             String myStrings
     * 
     * Output:            Array of chracters
     ************************************************************************************************* */
    public static char[] stringToChar(String myStrings)
    {
        char[] array = myStrings.toCharArray();

        return array;
    }    
}
