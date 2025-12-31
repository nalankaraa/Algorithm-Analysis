#ifndef MAX_SUBSEQUENCE_H
#define MAX_SUBSEQUENCE_H

#include <vector>
using namespace std;

/*-------------------------------------------------
  Max Subsequence Sum Algorithms
-------------------------------------------------*/
int maxSubsequenceSum1(const vector<int>& A);
int maxSubsequenceSum2(const vector<int>& A);
int maxSubsequenceSum3(const vector<int>& A);
int maxSubsequenceSum4(const vector<int>& A);

/*-------------------------------------------------
  Helper Functions (Divide and Conquer)
-------------------------------------------------*/
int max3(int a, int b, int c);
int maxSubSumRec(const vector<int>& A, int left, int right);

#endif
