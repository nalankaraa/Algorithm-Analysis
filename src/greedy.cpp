#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*-------------------------------------------------
  1) Greedy Path in NxN Cost Matrix
  Only RIGHT or DOWN moves are allowed
-------------------------------------------------*/
int greedyMinCostPath(const vector<vector<int>>& cost)
{
    int n = cost.size();
    int i = 0, j = 0;
    int totalCost = cost[0][0];

    while (i < n - 1 || j < n - 1)
    {
        if (i == n - 1)
            j++;
        else if (j == n - 1)
            i++;
        else if (cost[i + 1][j] < cost[i][j + 1])
            i++;
        else
            j++;

        totalCost += cost[i][j];
    }
    return totalCost;
}

/*-------------------------------------------------
  2) Job Scheduling Problem
  Greedy Strategy 1: Sort by processing time
-------------------------------------------------*/
double greedyJobScheduler1(vector<int> jobs)
{
    sort(jobs.begin(), jobs.end());

    int time = 0;
    int totalCompletionTime = 0;

    for (int t : jobs)
    {
        time += t;
        totalCompletionTime += time;
    }
    return (double)totalCompletionTime / jobs.size();
}

/*-------------------------------------------------
  3) Job Scheduling Problem
  Greedy Strategy 2: Min-Heap
-------------------------------------------------*/
double greedyJobScheduler2(const vector<int>& jobs)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int t : jobs)
        minHeap.push(t);

    int time = 0;
    int totalCompletionTime = 0;

    while (!minHeap.empty())
    {
        int job = minHeap.top();
        minHeap.pop();

        time += job;
        totalCompletionTime += time;
    }
    return (double)totalCompletionTime / jobs.size();
}

/*-------------------------------------------------
  Activity Structure
-------------------------------------------------*/
struct Activity
{
    int start;
    int finish;
};

/*-------------------------------------------------
  Greedy Algorithm 1 (NOT always optimal)
  Sort by activity duration
-------------------------------------------------*/
vector<Activity> activityGreedy1(vector<Activity> activities)
{
    sort(activities.begin(), activities.end(),
         [](Activity a, Activity b)
         {
             return (a.finish - a.start) < (b.finish - b.start);
         });

    vector<Activity> result;
    int lastFinish = -1;

    for (auto a : activities)
    {
        if (a.start >= lastFinish)
        {
            result.push_back(a);
            lastFinish = a.finish;
        }
    }
    return result;
}

/*-------------------------------------------------
  Greedy Algorithm 2 (ALWAYS optimal)
  Sort by finish time
-------------------------------------------------*/
vector<Activity> activityGreedy2(vector<Activity> activities)
{
    sort(activities.begin(), activities.end(),
         [](Activity a, Activity b)
         {
             return a.finish < b.finish;
         });

    vector<Activity> result;
    int lastFinish = 0;

    for (auto a : activities)
    {
        if (a.start >= lastFinish)
        {
            result.push_back(a);
            lastFinish = a.finish;
        }
    }
    return result;
}

