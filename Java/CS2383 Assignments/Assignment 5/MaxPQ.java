
public class MaxPQ<Key extends Comparable<Key>> {
    private Key[] pq;                    // store items at indices 1 to n
    private int n;                       // number of items on priority queue

    public MaxPQ(int initCapacity) {
        pq = (Key[]) new Comparable[initCapacity + 1];
        n = 0;
    }

    public boolean isEmpty() {
        return n == 0;
    }

    public int size() {
        return n;
    }

    public Key max() {
        if (isEmpty()) return null;
        return pq[1];
    }

    public void insert(Key x) {
        pq[++n] = x;
        swim(n);
    }

    public Key delMax() {
        if (isEmpty()) return null;
        Key max = pq[1];
        exch(1, n--);
        sink(1);
        pq[n+1] = null;     // to avoid loitering and help with garbage collection
        return max;
    }

    private void swim(int k) {
        while (k > 1 && less(k/2, k)) {
            exch(k/2, k);
            k = k/2;
        }
    }

    private void sink(int k) {
        while (2*k <= n) {
            int j = 2*k;
            if (j < n && less(j, j+1)) j++;
            if (!less(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    private boolean less(int i, int j) {
         return pq[i].compareTo(pq[j]) < 0;
    }

    private void exch(int i, int j) {
        Key swap = pq[i];
        pq[i] = pq[j];
        pq[j] = swap;
    }

}