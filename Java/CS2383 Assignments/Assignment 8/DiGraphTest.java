

/********************************************************************************************
 * This program tests out the digraph list 
 * 
 * @Cynthia Haque Question 1 & 2
 * @date 12-2-2024
 * @version 2024 
 ******************************************************************************************** */
public class DiGraphTest 
{
    public static void main(String[] args) 
    {
        
        //create a DiGraphAdjListImplem
        DiGraphAdjListImplem diGraphAdjList = new DiGraphAdjListImplem(6);

        //add an edge
        diGraphAdjList.addEdge(1, 4);
        diGraphAdjList.addEdge(2, 4);
        diGraphAdjList.addEdge(2, 3);
        diGraphAdjList.addEdge(1, 5);
    
        

        //adj method 
        System.out.println("Adjacency for vertex 1: " + diGraphAdjList.adj(1));
        System.out.println("Adjacency for vertex 2: " + diGraphAdjList.adj(2));

        
        
        DiGraphAdjListImplem transpose = diGraphAdjList.transpose();

        System.out.println(transpose);

        System.out.println(diGraphAdjList.toString());


    }
}

