#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int *harr;
    int capacity;
    int head_size;

public:
    MinHeap(int cap);

    void MinHeapify(int i);

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    int extractMin();

    int getMin() { return harr[0]; }

    void delKey(int i, int new_key);
    int insertKey(int i);
};

MinHeap::MinHeap(int cap)
{
    capacity = cap;
    head_size = 0;
    harr = new int[capacity];
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < head_size && harr[l] < harr[i])
    {
        smallest = l;
    }

    if (r < head_size && harr[r] < harr[smallest])
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swap(harr[smallest], harr[i]);
        MinHeapify(smallest);
    }
}

void MinHeap::delKey(int i, int new_key)
{
    harr[i] = new_key;

    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::insertKey(int k)
{
    if (head_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    head_size++;
    int i = head_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin()
{
    if (head_size == 0)
    {
        return -1;
    }

    if (head_size == 1)
    {
        head_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[head_size - 1];
    head_size--;
    MinHeapify(0);

    return root;
}
int main()
{
}