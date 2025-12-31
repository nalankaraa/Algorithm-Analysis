#ifndef RECURSIVE_H
#define RECURSIVE_H

#include <vector>
using namespace std;

/*-------------------------------------------------
  Basic Recursive Functions
-------------------------------------------------*/
int sumN(int n);

int sumArray1(const vector<int>& A, int N);
int sumArray2(const vector<int>& A, int left, int right);

int power(int a, int n);
int fastPower(int a, int n);

int fibonacci(int n);

/*-------------------------------------------------
  Tower of Hanoi
-------------------------------------------------*/
void hanoi(int n, char from, char aux, char to);

/*-------------------------------------------------
  Recursive Search Algorithms
-------------------------------------------------*/
int recursiveForwardSearch(const vector<int>& A,
                           int index,
                           int N,
                           int key);

int recursiveBackwardSearch(const vector<int>& A,
                            int N,
                            int key);

int recursiveBinarySearch(const vector<int>& A,
                           int left,
                           int right,
                           int key);

/*-------------------------------------------------
  Recursive Digit Sum (Super Digit)
-------------------------------------------------*/
int superDigit(long long n);

#endif
