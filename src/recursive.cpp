#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 1 + 2 + ... + N (Recursive)
 Base Case: n == 1
*/
int sumN(int n)
{
    if (n == 1)
        return 1;

    return sumN(n - 1) + n;
}

/*
 Sum of array A[0..N-1] - Version I
 Base Case: N == 1
*/
int sumArray1(const vector<int>& A, int N)
{
    if (N == 1)
        return A[0];

    return sumArray1(A, N - 1) + A[N - 1];
}

/*
 Sum of array A[0..N-1] - Version II (Divide and Conquer)
*/
int sumArray2(const vector<int>& A, int left, int right)
{
    if (left == right)
        return A[left];

    int mid = (left + right) / 2;

    return sumArray2(A, left, mid) +
           sumArray2(A, mid + 1, right);
}

/*
 a^n (Recursive)
 Base Cases:
 n == 0 -> 1
 n == 1 -> a
*/
int power(int a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;

    return power(a, n - 1) * a;
}

/*
 a^n (Fast Recursive Power)
*/
int fastPower(int a, int n)
{
    if (n == 1)
        return a;

    int temp = fastPower(a, n / 2);

    if (n % 2 == 0)
        return temp * temp;
    else
        return temp * temp * a;
}

/*
 Fibonacci Numbers (Recursive)
 F(0) = 0
 F(1) = 1
*/
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
 Tower of Hanoi
*/
void hanoi(int n, char from, char aux, char to)
{
    if (n <= 0)
        return;

    hanoi(n - 1, from, to, aux);
    cout << "Move disk from " << from << " to " << to << endl;
    hanoi(n - 1, aux, from, to);
}

/*
 Recursive Forward Linear Search
*/
int recursiveForwardSearch(const vector<int>& A, int index, int N, int key)
{
    if (N == 0)
        return -1;

    if (A[index] == key)
        return 0;

    int res = recursiveForwardSearch(A, index + 1, N - 1, key);
    if (res == -1)
        return -1;

    return res + 1;
}

/*
 Recursive Backward Linear Search
*/
int recursiveBackwardSearch(const vector<int>& A, int N, int key)
{
    if (N == 0)
        return -1;

    if (A[N - 1] == key)
        return N - 1;

    return recursiveBackwardSearch(A, N - 1, key);
}

/*
 Recursive Binary Search
*/
int recursiveBinarySearch(const vector<int>& A, int left, int right, int key)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (A[mid] == key)
        return mid;
    else if (key < A[mid])
        return recursiveBinarySearch(A, left, mid - 1, key);
    else
        return recursiveBinarySearch(A, mid + 1, right, key);
}

/*
 Recursive Digit Sum (Super Digit)
*/
int superDigit(long long n)
{
    if (n < 10)
        return n;

    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return superDigit(sum);
}
