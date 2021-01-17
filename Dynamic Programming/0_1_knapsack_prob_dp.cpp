/*
    Dynamic Programming approach for 0-1 knapsack problem
*/
#include <algorithm>
#include <iostream>
using namespace std;

// function finding maximum value , that can be added in knapsack
int max_value(int values[], int weights[], int pairs, int knapsack_wt)
{
    /*
        table[i][j] = maximum values that we can collect with first i items
                      and kanpsack weight j.
    */
    int table[pairs + 1][knapsack_wt + 1];

    // initializing first row, when pairs == 0
    for (int i = 0; i <= knapsack_wt; i++)
        table[0][i] = 0; // base case

    // initializing first column, when knapsack weight == 0
    for (int i = 0; i <= pairs; i++)
        table[i][0] = 0; // base case

    for (int i = 1; i <= pairs; i++)
    {
        for (int j = 1; j <= knapsack_wt; j++)
        {
            if (weights[i - 1] > j)
            {
                table[i][j] = table[i - 1][j];
            }
            else
            {
                table[i][j] = max(
                    values[i - 1] +
                        table[i - 1][j - weights[i - 1]],
                    table[i - 1][j]);
            }
        }
    }

    return table[pairs][knapsack_wt];
}

int main()
{
    int pairs;
    cout << "\nEnter total value of pairs : ";
    cin >> pairs;

    int values[pairs];  // store value
    int weights[pairs]; // store respective weights

    cout << "\nStart entering : weight value\n";
    for (int i = 0; i < pairs; i++)
    {
        cin >> weights[i] >> values[i];
    }

    int knapsack_wt;
    cout << "\nEnter knapsack weight : ";
    cin >> knapsack_wt;

    cout << "\nMaximum value in knapsack : "
         << max_value(values, weights, pairs, knapsack_wt);
    return 0;
}