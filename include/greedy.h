#ifndef GREEDY_H
#define GREEDY_H

#include <vector>
using namespace std;

/*-------------------------------------------------
  Greedy Path in NxN Cost Matrix
-------------------------------------------------*/
int greedyMinCostPath(const vector<vector<int>>& cost);

/*-------------------------------------------------
  Job Scheduling Problems
-------------------------------------------------*/
double greedyJobScheduler1(vector<int> jobs);
double greedyJobScheduler2(const vector<int>& jobs);

/*-------------------------------------------------
  Activity Structure
-------------------------------------------------*/
struct Activity
{
    int start;
    int finish;
};

/*-------------------------------------------------
  Activity Scheduling (Greedy)
-------------------------------------------------*/
vector<Activity> activityGreedy1(vector<Activity> activities);
vector<Activity> activityGreedy2(vector<Activity> activities);

#endif
