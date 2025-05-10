
class LinkedStack implements Stack
{
   private Node head;
   
   public LinkedStack()
   {
      head = null;
   }
   
   public boolean isEmpty()
   {
      if (head == null)
         return true;
      else
         return false;
   }
   
   public void push(String s)
   {
      Node n = new Node(s);
      if (isEmpty())
      {
        head = n;
      }
      else
      {
        n.setNext(head);
        head = n;
      }
   }
   
   public String pop()
   {
      String elem = null;
      if (!isEmpty())
      {
        elem = head.getStr();
        head = head.getNext();
      }
      return elem;
   }
  
   public String peek()
   {
      if (!isEmpty())
        return head.getStr();
      else
        return null;
   }
}

