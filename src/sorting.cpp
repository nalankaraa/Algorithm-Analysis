#include <iostream>
#include <vector>
using namespace std;

/*
 Selection Sort
 Time Complexity: O(N^2)
 In-place: Yes
 Stable: No
*/
void selectionSort(vector<int>& A)
{
    int n = A.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minIndex])
                minIndex = j;
        }

        int temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

/*
 Bubble Sort
 Time Complexity: O(N^2)
 In-place: Yes
 Stable: Yes
*/
void bubbleSort(vector<int>& A)
{
    int n = A.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

/*
 Insertion Sort
 Time Complexity:
 Worst Case: O(N^2)
 Best Case: O(N)
 In-place: Yes
 Stable: Yes
*/
void insertionSort(vector<int>& A)
{
    int n = A.size();

    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }
}

/*
 Merge Function
*/
void merge(vector<int>& A, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1)
        A[k++] = L[i++];

    while (j < n2)
        A[k++] = R[j++];
}

/*
 Merge Sort
 Time Complexity: O(N log N)
 Extra Space: O(N)
*/
void mergeSort(vector<int>& A, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);

        merge(A, left, mid, right);
    }
}

/*
 Utility Function
*/
void printArray(const vector<int>& A)
{
    for (int x : A)
        cout << x << " ";
    cout << endl;
}

