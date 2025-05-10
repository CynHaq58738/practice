
/****************************************************************************************
 * This program creates a LinkedList class
 *
 * @name Cynthia Haque
 * @date 9-22-2024
 * @version 2024 
 **************************************************************************************** */
public class LL 
{
    private Node head;

    public LL(Node head)
    {
        head = null;
    }

    public void setHead(Node head)
    {
        head = null;
    }

    public void addElement(String s)
    {
        Node curr = new Node(s);
        curr.setNext(head);
        head = curr;
    }

    public Node search(String s)
    {
        Node curr = head;
        while(curr !=null && !s.equals(curr.getStr()))
        {
            curr = curr.getNext();
        }
        return curr;
    }

    public Node getElement(int index)
    {
        int i = 0;

        Node curr = head;
        while(curr !=null && i<index )
        {
            curr = curr.getNext();
            i++;
        }
        return curr;
    }

    public void removeElement(Node elem)
    {
        if(elem == head)
        {
            head = elem.getNext();
        }
        else
        {
            Node prev = head;
            while(prev !=null && prev.getNext() != elem)
            {
                prev = prev.getNext();
            }
            if(prev != null)
            {
                prev.setNext(elem.getNext());
            }
        } 
    }

    public void insertElement(Node elem, int index)
    {
        if(index == 0)
        {
            elem.setNext(head);
            head = elem;
        }
        else
        {
            Node prev = getElement(index-1);
            elem.setNext(prev.getNext());
            prev.setNext(elem);
        }
    }

    public void printLL(LL myLL)
    {
        System.out.println("My List: ");
        Node curr = head;
        while(curr !=null)
        {
            System.out.println(" " + curr.getStr());
            curr = curr.getNext();
        }
        System.out.println("\n");
    }
}

