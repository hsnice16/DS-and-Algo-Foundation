/*
    Memoization Implementation in Dynamic Programming - Top-Down Approach.
*/
#include <iostream>
using namespace std;

/*
    optimization of fibonacci numbers implementation
    time comlexity : O(n) rather than exponential ,as in older recursive implementation.
*/
int fib(int n, int memo[])
{
    if (memo[n] == -1) // if we encounter this number first number
    {
        int res;
        if (n == 0 || n == 1)
        {
            res = n;
        }
        else
        {
            res = fib(n - 1, memo) + fib(n - 2, memo);
        }
        memo[n] = res;
    }
    return memo[n];
}

int main()
{
    int n;
    cout << "\nEnter which nth value you want of fibonacci : ";
    cin >> n;

    /*
        dimension of memo array, is based on no. of parameters we are changing in
        function.
        And size on minimum and maximum value of that parameter.
        In this problem, min = 0 and max = n, so our size is n+1
    */
    int memo[n + 1];
    // initializing memo array , with initiale value -1
    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    cout << n << "th value of fibonacci : " << fib(n, memo);

    return 0;
}