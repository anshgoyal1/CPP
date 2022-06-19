#include <iostream>
using namespace std;

bool check_minheap(int A[], int m, int n)
{
    // if left child exists, check if is heap
    bool left = (2 * m + 1 >= n) || (A[m] <= A[2 * m + 1]) && check_minheap(A, 2 * m + 1, n);

    // if right child exists, check if it is heap
    bool right = (2 * m + 2 >= n) || (A[m] <= A[2 * m + 2] && check_minheap(A, 2 * m + 2, n));

    // returns true if both left and right child are heaps
    return left && right;
}

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    if (check_minheap(A, 0, N))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}