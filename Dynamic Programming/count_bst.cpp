/*
    Problem : Count BST's (unique in structure) with n keys (keys are distinct)
*/
#include <iostream>
using namespace std;

/* 
    function finding total unique BST's with n keys. 
    Recursion Formula :
        res(n) = res(0)*res(n-1) + res(1)*res(n-2) +...+res(n-1)*res(0)
               = summation from i=0 to i=(n-1) of [res(i)*res(n-i-1)]
        res(0) = 1

    time complexity : O(n^2)
    auxiliary space : theta(n)

    ***it is an application of Catalan Numbers
        res(n) = (1 / (n+1)) * ((2n) Combination (n))
*/
int count_bst(int n)
{
    /*
        if (n == 0)
            return 1;

        int res = 0;
        for (int i = 1; i <= n; i++) // with i as root
        {
            res += (count_bst(i - 1) * count_bst(n - i));
        }
        return res;
    */

    // DP based
    int table[n + 1];
    table[0] = 1; // base case

    for (int i = 1; i <= n; i++)
    {
        table[i] = 0;
        for (int j = 0; j < i; j++)
        {
            table[i] += table[j] * table[i - j - 1];
        }
    }

    return table[n];
}

int main()
{
    int n; // number of unique keys
    cout << "\nEnter number of unique keys : ";
    cin >> n;

    cout << "\nNumber of Unique BST's : " << count_bst(n);
    return 0;
}