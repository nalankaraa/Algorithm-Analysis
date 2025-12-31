#include <iostream>
#include <vector>
using namespace std;

/*
 Algorithm 1 for Max Subsequence Sum
 Time Complexity: O(n^3)
*/
int maxSubsequenceSum1(const vector<int>& A)
{
    int maxSum = 0;

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i; j < A.size(); j++)
        {
            int thisSum = 0;

            for (int k = i; k <= j; k++)
                thisSum += A[k];

            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

/*
 Algorithm 2 for Max Subsequence Sum
 Time Complexity: O(n^2)
*/
int maxSubsequenceSum2(const vector<int>& A)
{
    int maxSum = 0;

    for (int i = 0; i < A.size(); i++)
    {
        int thisSum = 0;

        for (int j = i; j < A.size(); j++)
        {
            thisSum += A[j];

            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

/*
 Algorithm 3 for Max Subsequence Sum
 Divide and Conquer
 Time Complexity: O(n log n)
*/
int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maxSubSumRec(const vector<int>& A, int left, int right)
{
    if (left == right)
        return max(0, A[left]);

    int center = (left + right) / 2;

    int maxLeftSum  = maxSubSumRec(A, left, center);
    int maxRightSum = maxSubSumRec(A, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; i--)
    {
        leftBorderSum += A[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int i = center + 1; i <= right; i++)
    {
        rightBorderSum += A[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3(maxLeftSum,
                maxRightSum,
                maxLeftBorderSum + maxRightBorderSum);
}

int maxSubsequenceSum3(const vector<int>& A)
{
    return maxSubSumRec(A, 0, A.size() - 1);
}

/*
 Algorithm 4 for Max Subsequence Sum
 Kadane Algorithm
 Time Complexity: O(n)
*/
int maxSubsequenceSum4(const vector<int>& A)
{
    int maxSum = 0, thisSum = 0;

    for (int i = 0; i < A.size(); i++)
    {
        thisSum += A[i];

        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}

