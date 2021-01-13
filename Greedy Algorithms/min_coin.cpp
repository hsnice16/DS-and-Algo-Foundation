/*
    This is the problem of minimization .
    Like : consider we have given infinite supply of 10, 5, 2, 1 coins,
            And we want to make 52 Rupees , then how many minimum number 
            of coins , we need ?
*/
#include <algorithm>
#include <iostream>
using namespace std;

// function calculating minimum numbers of coins required
int min_coin(int coin_num, int coins_val[], int make_rupe)
{
    // sort the coins_val in decreasing order
    sort(coins_val, coins_val + coin_num, greater<int>());

    int res = 0; // to store result

    // find minimum numbers of coin
    for (int i = 0; i < coin_num; i++)
    {
        if (coins_val[i] <= make_rupe)
        {
            int temp = make_rupe / coins_val[i];
            res += temp;
            make_rupe -= temp * coins_val[i];
        }
        if (make_rupe == 0)
        {
            break;
        }
    }
    return res;
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