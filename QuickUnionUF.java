


/**********************************************************************************************
 * This program creates the class Quick Union Weighted
 *  
 * @name Cynthia Haque
 * @date 10-4-2024
 * @version 2024 
 ********************************************************************************************** */
public class QuickUnionUF
{
    //create a integer array for ids and the sz
    private int[] id;
    private int[] sz;

    public QuickUnionUF(int N)
    {
        id = new int[N];
        for (int i = 0; i < N; i++) 
        {
            id[i] = i;
        }
    }

    public int find(int i)
    {
        while(i != id[i])
        {
            i = id[i];
        }
        return i;
    }

    public void union(int p, int q)
    {
        int i = find(p);
        int j = find(q);

        //already connected
        if(i == j)
        {
            return;   
        }
        else
        {
            if(sz[i] < sz[j])
            {
                //ids of i point to j
                id[i] = j;
                //j's size is added with i's size
                sz[j] += sz[i];
            }
            else
            {
                //ids of j point to i
                id[j] = i;
                //i's size is added with j's size
                sz[i] += sz[j]; 
            }
        }
    }
    
}
