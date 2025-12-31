#include "heap.h"
#include <iostream>
#include <climits>
using namespace std;

MinHeap::MinHeap(int capacity)
{
    H.resize(capacity + 1);
    H[0] = INT_MIN;   // Sentinel
    N = 0;
}

bool MinHeap::isEmpty() const
{
    return N == 0;
}

int MinHeap::findMin() const
{
    if (isEmpty())
        return -1;
    return H[1];
}

void MinHeap::percolateDown(int i)
{
    int child;
    int tmp = H[i];

    while (2 * i <= N)
    {
        child = 2 * i;
        if (child != N && H[child + 1] < H[child])
            child++;

        if (H[child] < tmp)
            H[i] = H[child];
        else
            break;

        i = child;
    }
    H[i] = tmp;
}

void MinHeap::percolateUp(int i)
{
    int tmp = H[i];
    while (H[i / 2] > tmp)
    {
        H[i] = H[i / 2];
        i /= 2;
    }
    H[i] = tmp;
}

void MinHeap::insert(int key)
{
    if (N + 1 >= H.size())
        H.resize(H.size() * 2);

    int hole = ++N;
    H[hole] = key;
    percolateUp(hole);
}

int MinHeap::deleteMin()
{
    if (isEmpty())
        return -1;

    int minItem = H[1];
    H[1] = H[N--];
    percolateDown(1);

    return minItem;
}

void MinHeap::buildHeap(const vector<int>& A)
{
    N = A.size();
    H.resize(N + 1);
    H[0] = INT_MIN;

    for (int i = 0; i < A.size(); i++)
        H[i + 1] = A[i];

    for (int i = N / 2; i > 0; i--)
        percolateDown(i);
}

void MinHeap::decreaseKey(int pos, int delta)
{
    if (pos < 1 || pos > N)
        return;

    H[pos] -= delta;
    percolateUp(pos);
}

void MinHeap::increaseKey(int pos, int delta)
{
    if (pos < 1 || pos > N)
        return;

    H[pos] += delta;
    percolateDown(pos);
}

void MinHeap::deleteKey(int pos)
{
    if (pos < 1 || pos > N)
        return;

    H[pos] = H[N--];
    percolateDown(pos);
}

void MinHeap::mergeHeap(MinHeap& H2)
{
    for (int i = 1; i <= H2.N; i++)
        H.push_back(H2.H[i]);

    N = H.size() - 1;

    for (int i = N / 2; i > 0; i--)
        percolateDown(i);
}

void MinHeap::printHeap() const
{
    for (int i = 1; i <= N; i++)
        cout << H[i] << " ";
    cout << endl;
}
