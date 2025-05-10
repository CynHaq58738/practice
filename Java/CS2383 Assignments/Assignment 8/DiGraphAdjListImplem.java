
import java.util.*;

/********************************************************************************************
 * This program implements the Di graph adjacent list.
 * 
 * @Cynthia Haque Question 1 & 2
 * @date 12-2-2024
 * @version 2024 
 ******************************************************************************************** */
class DiGraphAdjListImplem
{
   private int V;
   private LinkedList<Integer>[] adj;
   
   public DiGraphAdjListImplem(int V)
   {
      this.V = V;
      adj = new LinkedList[V];
      for (int v=0; v < V; v++)
         adj[v] = new LinkedList<Integer>();
   }
   
   public void addEdge(int v, int w)
   {
      //add edge v to w
      adj[v].add(w);
   }
   
   public Iterable<Integer> adj(int v)
   {
      return adj[v];
   }

   public DiGraphAdjListImplem transpose()
   {
        //ctreate a new DiGraphAdjMatrixImplem
        DiGraphAdjListImplem transposeGraph = new DiGraphAdjListImplem(V);
        for(int v = 0; v<V ; v++)
        {
            //for each adjacent vertex in w
            for(int w : adj[v])
            {
                //add the reversed edge
                transposeGraph.addEdge(w, v);
            }
        }
        return transposeGraph;
   }
   
   public String toString()
   {
      String str = "";
      for (int i=0; i < V; i++)
      {
         str += "Vertex " + i + " is connected to: ";
         for (int v : adj[i])
            str += v + " ";
         str += "\n";
      }
      return str;
   }
   
}
