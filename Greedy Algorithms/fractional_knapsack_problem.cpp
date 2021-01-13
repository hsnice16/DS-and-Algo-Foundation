/*
              I_1   I_2   I_3
    ___________________________
   | weight | 50  | 20  | 30  |
    ---------------------------
   | values | 600 | 500 | 400 |
    
    we are given a set of items, I_1, I_2 and I_3 in this case. we
    have given there weights 50, 20, 30 and their values 600, 500 and
    400.
    we also have given knapsack(a bag) capacity = 70.

    Target : to store maximum value in knapsack and the advantage here
             we have , that we can collect item partially (like store 20 
             kg weigth out of 50 kg. that's why fractional knapsack problem).
*/
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
    sorting according to (value / weight), value per unit of weight,
    in descending order.

    Idea : if value per unit weight of an item is large we should take
            as maximum as possible.
*/
bool valueByweight(pair<int, int> &p1, pair<int, int> &p2)
{
    return ((p1.second / p1.first) > (p2.second / p2.first));
}

/*
    function calculating maximum value we can store in knapsack 
    time complexity : O(nlogn) // required for sorting
*/
int calc_max_value(int ttl_item, vector<pair<int, int>> item_arr, int knapsack_wt)
{
    // sort in descending order
    sort(item_arr.begin(), item_arr.end(), valueByweight);

    int res = 0; // to store result

    // traverse the item array
    for (int i = 0; i < ttl_item; i++)
    {
        pair<int, int> curr_item = item_arr[i];
        if (curr_item.first <= knapsack_wt) // weight is less than knapsack_wt
        {
            knapsack_wt -= curr_item.first; // remaining knapsack weight
            res += curr_item.second;        // take value complete
        }
        else
        {                                                                // weight is not less than kanpsack
            res += (curr_item.second / curr_item.first) * (knapsack_wt); // take weight partially
            return res;
        }
    }
    return res;
}

int main()
{
    // total item
    int ttl_item;
    cout << "\nEnter number of items : ";
    cin >> ttl_item;

    vector<pair<int, int>> item_arr; // vector to store items
    cout << "\nStart entering items - weights & values : \n";
    for (int i = 0; i < ttl_item; i++)
    {
        cout << "For item " << i + 1 << ": \n";
        int wt, val;
        cout << "enter weight : ";
        cin >> wt;
        cout << "enter values : ";
        cin >> val;
        item_arr.push_back(make_pair(wt, val));
        cout << '\n';
    }

    int knapsack_wt;
    cout << "\nEnter knapsack capacity : ";
    cin >> knapsack_wt;

    int max_val = calc_max_value(ttl_item, item_arr, knapsack_wt);
    cout << "\nMaximum value , we can store in knapsack : " << max_val << endl;
    return 0;
}