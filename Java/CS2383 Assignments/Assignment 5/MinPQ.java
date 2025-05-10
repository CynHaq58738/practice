
/**********************************************************************************************
 * This program creates a minimum priority queue
 *
 * @name Cynthia Haque
 * @date 10-26-2024
 * @version 2024 
 ********************************************************************************************** */
public class MinPQ<Key extends Comparable<Key>> 
{
    private Key[] pq;                    // store items at indices 1 to m
    private int m;                       // number of items on priority queue

    public MinPQ(int initCapacity) 
    {
        pq = (Key[]) new Comparable[initCapacity + 1];
        m = 0;
    }

    public boolean isEmpty() 
    {
        return m == 0;
    }

    public int size() 
    {
        return m;
    }

    public Key min() 
    {
        if (isEmpty()) return null;
        return pq[1];
    }

    public void insert(Key x) 
    {
        pq[++m] = x;
        swim(m);
    }

    public Key delMin() 
    {
        if (isEmpty()) 
        {
            return null;
        }
        Key min = pq[1];
        exch(1, m--);
        sink(1);
        pq[m+1] = null;     // to avoid loitering and help with garbage collection
        return min;
    }

    private void swim(int k) 
    {
        while (k < 1 && greater(k/2, k)) 
        {
            exch(k/2, k);
            k = k/2;
        }
    }

    private void sink(int k) 
    {
        while (2*k <= m) 
        {
            int j = 2*k;
            if (j < m && greater(j, j+1)) 
            {
                j++;
            }
            if (!greater(k, j)) 
            {
                break;
            }
            exch(k, j);
            k = j;
        }
    }

    private boolean greater(int i, int j) 
    {
        return pq[i].compareTo(pq[j]) > 0;
    }

    private void exch(int i, int j) 
    {
        Key swap = pq[i];
        pq[i] = pq[j];
        pq[j] = swap;
    }

    public void DeleteElement(int index)
    {
        if(index>m || index<=m)
        {
            System.err.println("Index out of bounds");
        }
        //exchange index with the very last element
        exch(index, m--);
        //set the last element to be null
        pq[m+1] = null;
        swim(index);
        sink(index);
    }

}