#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
private:
    int *harr;
    int heap_size;
    int capacity;

public:
    MinHeap(int c)
    {
        heap_size = 0;
        capacity = c;
        harr = new int[capacity];
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap_size && harr[l] < harr[i])
        {
            smallest = l;
        }

        if (r < heap_size && harr[r] < harr[smallest])
        {
            smallest = r;
        }

        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int ExtractMin()
    {
        if (heap_size == 0)
        {
            return INT_MIN;
        }
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);
        return root;
    }

    void insertKey(int k)
    {
        if (heap_size == capacity)
        {
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }

    int getMin()
    {
        return harr[0];
    }

    void decreaseKey(int i, int new_val)
    {
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        ExtractMin();
    }
};

int main()
{
}