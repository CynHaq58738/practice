
/********************************************************************************************
 * This program implements the Di graph adjacent matrix.
 * 
 * @Cynthia Haque Question 1 & 2
 * @date 12-2-2024
 * @version 2024 
 ******************************************************************************************** */

class DiGraphAdjMatrixImplem
{
   private int V;
   private int[][] adj;
   
   public DiGraphAdjMatrixImplem(int V)
   {
      this.V = V;
      adj = new int[V][V];
   }
   
   public void addEdge(int v, int w)
   {
      //setting adjacent edges v and w to 1 to create an edge from v to w
      adj[v][w] = 1;
   }

   public DiGraphAdjMatrixImplem transpose()
   {
        //ctreate a new DiGraphAdjMatrixImplem
        DiGraphAdjMatrixImplem transposeGraph = new DiGraphAdjMatrixImplem(V);
        for(int v = 0; v<V ; v++)
        {
            for(int w = 0; w<V; w++)
            {
                if(adj[v][w] == 1)
                {
                    //reverse the order
                    transposeGraph.addEdge(w, v);
                }
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
         for (int j = 0; j < V; j++)
         {
            if (adj[i][j] == 1)
               str += j + " ";
         }
         str += "\n";
      }
      return str;
   }
   
}

