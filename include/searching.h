#ifndef SEARCHING_H
#define SEARCHING_H

#include <vector>
using namespace std;

/*-------------------------------------------------
  Searching Algorithms
-------------------------------------------------*/
int forwardLinearSearch(const vector<int>& A, int x);
int backwardLinearSearch(const vector<int>& A, int x);
int binarySearch(const vector<int>& A, int x);

#endif
