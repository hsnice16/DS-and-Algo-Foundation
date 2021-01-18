/*
    Implementation of Binomial Coefficient Problem.

    **combination formula
*/
#include <iostream>
using namespace std;

/*
    function finding value of Binomial Coefficient.

    Optimal Substructure : 
        C(n, k) = C(n-1, k-1) + C(n-1, k)
        C(n, 0) = C(n, n) = 1
*/
int binomialCoeff(int n, int k)
{
    int table[n + 1][k + 1];

    // initializing first row, when n = 0, all values are 0
    for (int i = 0; i <= k; i++)
        table[0][i] = 0;

    // initializing firt column, when k = 0, all values are 1
    for (int i = 0; i <= n; i++)
        table[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i == j)
                table[i][j] = 1;
            else
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
        }
    }
    return table[n][k];
}

int main()
{
    int n, k;
    cout << "\nEnter value of n : ";
    cin >> n;

    cout << "\nEnter value of k : ";
    cin >> k;

    cout << "\nValue of Binomial Coefficient for n : " << n
         << " and k : " << k << " is : " << binomialCoeff(n, k);
    return 0;
}