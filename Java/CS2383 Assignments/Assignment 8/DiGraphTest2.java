
public class DiGraphTest2 
{
    public static void main(String[] args) 
    {
         //create a DiGraphAdjListImplem
         DiGraphAdjMatrixImplem diGraphAdjMatrix = new DiGraphAdjMatrixImplem(6);

         //add an edge
         diGraphAdjMatrix.addEdge(1, 1);
         diGraphAdjMatrix.addEdge(2, 4);
         diGraphAdjMatrix.addEdge(2, 3);
         diGraphAdjMatrix.addEdge(1, 5);
       
         
         DiGraphAdjMatrixImplem transpose1 = diGraphAdjMatrix.transpose();
 
         System.out.println(transpose1);
 
         System.out.println(diGraphAdjMatrix.toString());
  
    }
    
}
