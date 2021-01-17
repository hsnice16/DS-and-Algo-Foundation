/*
    Given an infinite supply of coins, want to make a sum of coins.
    Using minimum coins
*/
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

/*
// function calculating minimum numbers of coins required
int min_coin(int coin_num, int coins_val[], int make_rupe)
{
    if (make_rupe == 0)
        return 0;

    int res = INT_MAX;

    for (int i = 0; i < coin_num; i++)
    {
        if (coins_val[i] <= make_rupe)
        {
            int sub_res = min_coin(coin_num, coins_val, make_rupe - coins_val[i]);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
    return res;
}
*/
// DP version
int min_coin(int coin_num, int coins_val[], int make_rupe)
{
    int table[make_rupe + 1]; /* table[i] -> minimum number of coins required to make rupe i */
    table[0] = 0;             // base case of recursive version

    fill(table + 1, table + make_rupe + 1, INT_MAX); // filling else value as infinite

    // filliing the table
    for (int i = 1; i <= make_rupe; i++)
    {
        for (int j = 0; j < coin_num; j++)
        {
            if (coins_val[j] <= i)
            {
                int sub_res = table[i - coins_val[j]];
                if (sub_res != INT_MAX)
                {
                    table[i] = min(table[i], sub_res + 1);
                }
            }
        }
    }

    return table[make_rupe];
}

int main()
{
    // number of coins we have
    int coin_num;
    cout << "\nEnter number of coins we have : ";
    cin >> coin_num;

    // coins values
    int coins_val[coin_num];
    for (int i = 0; i < coin_num; i++)
    {
        cout << "\nCoin " << i + 1 << " value: ";
        cin >> coins_val[i];
    }

    int make_rupe;
    cout << "\nHow much Rupees you want to make ?: ";
    cin >> make_rupe;

    int min_c = min_coin(coin_num, coins_val, make_rupe);
    cout << "\nMinimum number of coins required : " << min_c << endl;

    return 0;
}