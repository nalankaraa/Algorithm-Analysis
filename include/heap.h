#ifndef HEAP_H
#define HEAP_H

#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> H;
    int N;

    void percolateDown(int i);
    void percolateUp(int i);

public:
    MinHeap(int capacity = 100);

    bool isEmpty() const;
    int findMin() const;

    void insert(int key);
    int deleteMin();

    void buildHeap(const vector<int>& A);

    void decreaseKey(int pos, int delta);
    void increaseKey(int pos, int delta);
    void deleteKey(int pos);

    void mergeHeap(MinHeap& H2);

    void printHeap() const;
};

#endif
