#ifndef SORTING_H
#define SORTING_H

#include <vector>
using namespace std;

/*-------------------------------------------------
  Sorting Algorithms
-------------------------------------------------*/
void selectionSort(vector<int>& A);
void bubbleSort(vector<int>& A);
void insertionSort(vector<int>& A);

/*-------------------------------------------------
  Merge Sort
-------------------------------------------------*/
void merge(vector<int>& A, int left, int mid, int right);
void mergeSort(vector<int>& A, int left, int right);

/*-------------------------------------------------
  Utility Function
-------------------------------------------------*/
void printArray(const vector<int>& A);

#endif
