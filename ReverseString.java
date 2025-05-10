/*************************************************
 * This program reverses a string
 *************************************************/

 public class ReverseString
 {
    public static void main(String[] args) 
    {
        String[] arr = {"Good Day Mate"};

        //create a for each loop to iterate through each element in the array
        for(String i : arr)
        {
            //create a char array and set it to be the original array to be of char
            char[] charArr = i.toCharArray();
            //create left and right pointers
            int right = charArr.length-1;
            int left = 0;

            //traverse through all the elements in the array
            while(right>left)
            {
                //swap the right with left
                char temp = charArr[left];
                charArr[left] = charArr[right];
                charArr[right] = temp;

                //decrement the right each time and increment the left each time
                right--;
                left++;
            }

            //create a string object to read in the charArr
            String revString = new String(charArr);

            System.out.println("Reversed String: " + revString);

        }
           
    }
 }
