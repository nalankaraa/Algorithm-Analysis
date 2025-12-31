#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

#include <vector>
using namespace std;

/*-------------------------------------------------
  Fibonacci
-------------------------------------------------*/
int fibRecursive(int n);
int fibTopDown(int n, vector<int>& memo);
int fibBottomUp(int n);

/*-------------------------------------------------
  Minimum Cost Path
-------------------------------------------------*/
int minCostRec(const vector<vector<int>>& cost, int i, int j);

int minCostTopDown(const vector<vector<int>>& cost,
                   int i, int j,
                   vector<vector<int>>& memo);

int minCostBottomUp(const vector<vector<int>>& cost);

/*-------------------------------------------------
  0-1 Knapsack
-------------------------------------------------*/
int knapsackRec(int W,
                const vector<int>& wt,
                const vector<int>& val,
                int n);

int knapsackTopDown(int W,
                    const vector<int>& wt,
                    const vector<int>& val,
                    int n,
                    vector<vector<int>>& memo);

int knapsackBottomUp(int W,
                     const vector<int>& wt,
                     const vector<int>& val,
                     int n);

#endif
