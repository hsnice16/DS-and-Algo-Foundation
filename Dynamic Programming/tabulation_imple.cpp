/*
    Tabulation Implementation in Dynamic Programming - Bottom-Up Approach
*/
#include <iostream>
using namespace std;

int fib(int n)
{
    int table[n + 1];
    table[0] = 0, table[1] = 1;
    for (int i = 2; i <= n; i++)
        table[i] = table[i - 1] + table[i - 2];
    return table[n];
}

int main()
{
    int n;
    cout << "\nEnter which nth value you want of fibonacci : ";
    cin >> n;

    cout << n << "th value of fibonacci : " << fib(n);
    return 0;
}