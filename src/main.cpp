#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <filesystem>

#include "sorting.h"
#include "searching.h"
#include "max_subsequence.h"
#include "recursive.h"
#include "heap.h"
#include "greedy.h"
#include "dynamic_programming.h"

using namespace std;
using namespace chrono;

/*-------------------------------------------------
  Yardımcı: Rastgele veri üret
-------------------------------------------------*/
vector<int> generateData(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = rand() % 200 - 100;
    return v;
}

/*-------------------------------------------------
  CSV Satırı Yaz
-------------------------------------------------*/
void writeCSV(ofstream& out,
              const string& category,
              const string& algorithm,
              const string& complexity,
              int n,
              double timeMs)
{
    out << category << ","
        << algorithm << ","
        << complexity << ","
        << n << ","
        << timeMs << "\n";
}

/*-------------------------------------------------
  MAX SUBSEQUENCE TEST
-------------------------------------------------*/
void testMaxSubsequence(const vector<int>& data, ofstream& csv)
{
    cout << "\n=== MAX SUBSEQUENCE ===\n";
    int n = data.size();

    auto start = high_resolution_clock::now();
    int r1 = maxSubsequenceSum1(data);
    auto end = high_resolution_clock::now();
    double t1 = duration<double, milli>(end - start).count();

    cout << "O(n^3): " << r1 << " | " << t1 << " ms\n";
    writeCSV(csv, "MaxSubsequence", "O(n^3)", "O(n^3)", n, t1);

    start = high_resolution_clock::now();
    int r2 = maxSubsequenceSum2(data);
    end = high_resolution_clock::now();
    double t2 = duration<double, milli>(end - start).count();

    cout << "O(n^2): " << r2 << " | " << t2 << " ms\n";
    writeCSV(csv, "MaxSubsequence", "O(n^2)", "O(n^2)", n, t2);

    start = high_resolution_clock::now();
    int r3 = maxSubsequenceSum3(data);
    end = high_resolution_clock::now();
    double t3 = duration<double, milli>(end - start).count();

    cout << "O(n log n): " << r3 << " | " << t3 << " ms\n";
    writeCSV(csv, "MaxSubsequence", "O(n log n)", "O(n log n)", n, t3);

    start = high_resolution_clock::now();
    int r4 = maxSubsequenceSum4(data);
    end = high_resolution_clock::now();
    double t4 = duration<double, milli>(end - start).count();

    cout << "O(n) (Kadane): " << r4 << " | " << t4 << " ms\n";
    writeCSV(csv, "MaxSubsequence", "Kadane", "O(n)", n, t4);
}

/*-------------------------------------------------
  SORTING TEST
-------------------------------------------------*/
void testSorting(const vector<int>& data, ofstream& csv)
{
    cout << "\n=== SORTING ===\n";
    int n = data.size();

    vector<int> A;

    A = data;
    auto s = high_resolution_clock::now();
    selectionSort(A);
    auto e = high_resolution_clock::now();
    double t = duration<double, milli>(e - s).count();
    cout << "Selection Sort: " << t << " ms\n";
    writeCSV(csv, "Sorting", "Selection", "O(n^2)", n, t);

    A = data;
    s = high_resolution_clock::now();
    bubbleSort(A);
    e = high_resolution_clock::now();
    t = duration<double, milli>(e - s).count();
    cout << "Bubble Sort:    " << t << " ms\n";
    writeCSV(csv, "Sorting", "Bubble", "O(n^2)", n, t);

    A = data;
    s = high_resolution_clock::now();
    insertionSort(A);
    e = high_resolution_clock::now();
    t = duration<double, milli>(e - s).count();
    cout << "Insertion Sort: " << t << " ms\n";
    writeCSV(csv, "Sorting", "Insertion", "O(n^2)", n, t);

    A = data;
    s = high_resolution_clock::now();
    mergeSort(A, 0, n - 1);
    e = high_resolution_clock::now();
    t = duration<double, milli>(e - s).count();
    cout << "Merge Sort:     " << t << " ms\n";
    writeCSV(csv, "Sorting", "Merge", "O(n log n)", n, t);
}

/*-------------------------------------------------
  SEARCHING TEST
-------------------------------------------------*/
void testSearching(vector<int> data, ofstream& csv)
{
    cout << "\n=== SEARCHING ===\n";
    int n = data.size();
    int key = data[n / 2];

    auto s = high_resolution_clock::now();
    int i1 = forwardLinearSearch(data, key);
    auto e = high_resolution_clock::now();
    double t1 = duration<double, milli>(e - s).count();
    cout << "Linear Forward: idx=" << i1 << " | " << t1 << " ms\n";
    writeCSV(csv, "Searching", "LinearForward", "O(n)", n, t1);

    s = high_resolution_clock::now();
    int i2 = backwardLinearSearch(data, key);
    e = high_resolution_clock::now();
    double t2 = duration<double, milli>(e - s).count();
    cout << "Linear Backward: idx=" << i2 << " | " << t2 << " ms\n";
    writeCSV(csv, "Searching", "LinearBackward", "O(n)", n, t2);

    sort(data.begin(), data.end());
    s = high_resolution_clock::now();
    int i3 = binarySearch(data, key);
    e = high_resolution_clock::now();
    double t3 = duration<double, milli>(e - s).count();
    cout << "Binary Search:  idx=" << i3 << " | " << t3 << " ms\n";
    writeCSV(csv, "Searching", "BinarySearch", "O(log n)", n, t3);
}

/*-------------------------------------------------
  HEAP TEST
-------------------------------------------------*/
void testHeap(ofstream& csv)
{
    cout << "\n=== HEAP ===\n";
    MinHeap h;

    auto s = high_resolution_clock::now();
    h.insert(10);
    h.insert(3);
    h.insert(7);
    h.insert(1);
    auto e = high_resolution_clock::now();
    double t = duration<double, milli>(e - s).count();

    cout << "Inserted 4 elements | Min = " << h.findMin() << endl;
    writeCSV(csv, "Heap", "Insert+FindMin", "O(log n)", 4, t);
}

/*-------------------------------------------------
  DYNAMIC PROGRAMMING TEST
-------------------------------------------------*/
void testDynamic(ofstream& csv)
{
    cout << "\n=== DYNAMIC PROGRAMMING ===\n";

    int n = 30;
    vector<int> memo(n + 1, -1);

    auto s = high_resolution_clock::now();
    int f = fibBottomUp(n);
    auto e = high_resolution_clock::now();
    double t = duration<double, milli>(e - s).count();

    cout << "Fibonacci(" << n << ") = " << f << " | " << t << " ms\n";
    writeCSV(csv, "DP", "FibonacciBottomUp", "O(n)", n, t);
}

/*-------------------------------------------------
  MAIN
-------------------------------------------------*/
int main()
{
    srand(time(nullptr));

    filesystem::create_directories("results");
    ofstream csv("results/analysis_results.csv");

    csv << "Category,Algorithm,Complexity,N,TimeMs\n";

    cout << "ALGORITHM ANALYSIS PROJECT\n";

    auto data = generateData(1000);

    testMaxSubsequence(data, csv);
    testSorting(data, csv);
    testSearching(data, csv);
    testHeap(csv);
    testDynamic(csv);

    csv.close();

    cout << "\nCSV written to: results/analysis_results.csv\n";
    cout << "PROGRAM FINISHED\n";

    return 0;
}
