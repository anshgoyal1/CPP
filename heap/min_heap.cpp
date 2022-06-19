#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
    int heap_size;
    int *heap;
    int capacity;

private:
    MinHeap(int c)
    {
        heap_size = 0;
        capacity = c;
        heap = new int[capacity];
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
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap_size && heap[l] < heap[smallest])
        {
            smallest = l;
        }

        if (r < heap_size && heap[r] < heap[smallest])
        {
            smallest = r;
        }

        if (smallest != i)
        {
            swap(heap[smallest], heap[i]);
            MinHeapify(smallest);
        }
    }

    void insert(int k)
    {
        if (heap_size == capacity)
        {
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        heap[i] = k;

        while (i != 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int new_val)
    {
        heap[i] = new_val;

        while (i != 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void maxHeapify(int i){
        int largest = i;
        int l = left(i);
        int r = right(i);

        if(l < heap_size && heap[l] > heap[largest]){
            largest = l;
        }

        if(r < heap_size && heap[r] > heap[largest]){
            largest = r;
        }

        if(largest != i){
            swap(heap[largest],heap[i]);
            maxHeapify(largest);
        }
    }
};

void maxHeapify(int arr[],int n,int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        maxHeapify(arr,n,largest);
    }
}

void heap_sort(int arr[],int n){
    for(int i = n / 2 - 1;i >= 0;i--){
        maxHeapify(arr,n,i);
    }

    for(int i = n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        maxHeapify(arr,i,0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heap_sort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}