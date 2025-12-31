#include <iostream>
#include <vector>
using namespace std;

/*
 Forward Linear Search
 Time Complexity: O(n)
*/
int forwardLinearSearch(const vector<int>& A, int x)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == x)
            return i;
    }
    return -1;
}

/*
 Backward Linear Search
 Time Complexity: O(n)
*/
int backwardLinearSearch(const vector<int>& A, int x)
{
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] == x)
            return i;
    }
    return -1;
}

/*
 Binary Search
 Array must be sorted
 Time Complexity: O(log n)
*/
int binarySearch(const vector<int>& A, int x)
{
    int left = 0;
    int right = A.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (A[mid] == x)
            return mid;
        else if (A[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

