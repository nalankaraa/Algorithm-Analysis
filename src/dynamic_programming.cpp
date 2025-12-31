#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*-------------------------------------------------
  1) Fibonacci - Naive Recursive
-------------------------------------------------*/
int fibRecursive(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

/*-------------------------------------------------
  2) Fibonacci - Top Down DP (Memoization)
-------------------------------------------------*/
int fibTopDown(int n, vector<int>& memo)
{
    if (memo[n] != -1)
        return memo[n];

    if (n == 0) return memo[n] = 0;
    if (n == 1) return memo[n] = 1;

    memo[n] = fibTopDown(n - 1, memo) + fibTopDown(n - 2, memo);
    return memo[n];
}

/*-------------------------------------------------
  3) Fibonacci - Bottom Up DP
-------------------------------------------------*/
int fibBottomUp(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

/*-------------------------------------------------
  4) Minimum Cost Path - Recursive
-------------------------------------------------*/
int minCostRec(const vector<vector<int>>& cost, int i, int j)
{
    if (i < 0 || j < 0)
        return INT_MAX;

    if (i == 0 && j == 0)
        return cost[0][0];

    return cost[i][j] +
           min(minCostRec(cost, i - 1, j),
               minCostRec(cost, i, j - 1));
}

/*-------------------------------------------------
  5) Minimum Cost Path - Top Down DP
-------------------------------------------------*/
int minCostTopDown(const vector<vector<int>>& cost,
                   int i, int j,
                   vector<vector<int>>& memo)
{
    if (i < 0 || j < 0)
        return INT_MAX;

    if (memo[i][j] != -1)
        return memo[i][j];

    if (i == 0 && j == 0)
        return memo[i][j] = cost[0][0];

    memo[i][j] = cost[i][j] +
                 min(minCostTopDown(cost, i - 1, j, memo),
                     minCostTopDown(cost, i, j - 1, memo));
    return memo[i][j];
}

/*-------------------------------------------------
  6) Minimum Cost Path - Bottom Up DP
-------------------------------------------------*/
int minCostBottomUp(const vector<vector<int>>& cost)
{
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int>(n));

    dp[0][0] = cost[0][0];

    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + cost[i][0];

    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j - 1] + cost[0][j];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = cost[i][j] +
                       min(dp[i - 1][j], dp[i][j - 1]);

    return dp[n - 1][n - 1];
}

/*-------------------------------------------------
  7) 0-1 Knapsack - Recursive
-------------------------------------------------*/
int knapsackRec(int W, const vector<int>& wt,
                const vector<int>& val, int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapsackRec(W, wt, val, n - 1);

    return max(knapsackRec(W, wt, val, n - 1),
               val[n - 1] +
               knapsackRec(W - wt[n - 1], wt, val, n - 1));
}

/*-------------------------------------------------
  8) 0-1 Knapsack - Top Down DP
-------------------------------------------------*/
int knapsackTopDown(int W, const vector<int>& wt,
                    const vector<int>& val, int n,
                    vector<vector<int>>& memo)
{
    if (n == 0 || W == 0)
        return 0;

    if (memo[n][W] != -1)
        return memo[n][W];

    if (wt[n - 1] > W)
        memo[n][W] = knapsackTopDown(W, wt, val, n - 1, memo);
    else
        memo[n][W] = max(
            knapsackTopDown(W, wt, val, n - 1, memo),
            val[n - 1] +
            knapsackTopDown(W - wt[n - 1], wt, val, n - 1, memo)
        );

    return memo[n][W];
}

/*-------------------------------------------------
  9) 0-1 Knapsack - Bottom Up DP
-------------------------------------------------*/
int knapsackBottomUp(int W, const vector<int>& wt,
                     const vector<int>& val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] +
                               dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

