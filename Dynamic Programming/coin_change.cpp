/*
    Implementation of coin change (count combinations) problem.
*/
#include <iostream>
using namespace std;

/*
// function finding combinations of coins that can make sum
int count_combinations(int coins[], int n, int sum)
{
    if (sum == 0) // if sum is 0 , then 1 combination possible (not include any coin)
        return 1;
    if (n == 0) // if size is 0, no combinations possible
        return 0;

    int res = count_combinations(coins, n - 1, sum); // not include last element
    if (coins[n - 1] <= sum)
    {
        res = res + count_combinations(coins, n, sum - coins[n - 1]); // include last element
    }

    return res;
}
*/

int count_combinations(int coins[], int n, int sum)
{
    int table[sum + 1][n + 1];
    /*
        table[i][j] : No. of combinations we can get with sum i and coins
                        form 1 to j.
    */
    // first row , with sum = 0 , combinations = 1
    for (int i = 0; i < n + 1; i++)
        table[0][i] = 1;

    // first column, with n = 0 , combinations = 0
    for (int i = 1; i < sum + 1; i++)
        table[i][0] = 0;

    // fill other cell
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            table[i][j] = table[i][j - 1];
            if (coins[j - 1] <= i)
                table[i][j] += table[i - coins[j - 1]][j];
        }
    }
    return table[sum][n];
}

int main()
{
    int coins[] = {1, 2, 3};
    int sum = 4;
    int n = 3;
    cout << "\nNumber of combinations : " << count_combinations(coins, n, sum);
    return 0;
}