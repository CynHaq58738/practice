
public class Node
{
   String str;
   Node next;
   
   public Node(String str)
   {
      this.str = str;
      next = null;
   }
   
   public String getStr()
   {
      return str;
   }
   
   public Node getNext()
   {
      return next;
   }
   
   public void setNext(Node next)
   {
      this.next = next;
   }
   
}

