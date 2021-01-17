/*
    Implementation of 0-1 knapsack problem, given only one 
    instance of (weight, value)
    pair . Either you pick a pair or not.

    Find maximum value ,we can add in knapsack.
*/
#include <algorithm>
#include <iostream>
using namespace std;

// function finding maximum value , that can be added in knapsack
int max_value(int values[], int weights[], int pairs, int knapsack_wt)
{
    if (pairs == 0 || knapsack_wt == 0)
        return 0;

    if (weights[pairs - 1] > knapsack_wt)
    {
        return max_value(values, weights, pairs - 1, knapsack_wt);
    }
    else
    {
        return max(
            values[pairs - 1] +
                max_value(values, weights, pairs - 1, knapsack_wt - weights[pairs - 1]),
            max_value(values, weights, pairs - 1, knapsack_wt));
    }
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