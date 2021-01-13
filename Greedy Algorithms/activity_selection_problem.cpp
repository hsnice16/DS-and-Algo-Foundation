/*
    we are given a set of activities , every activity is represented as pair.
    first element in pair represents start time, second element represents end time.

    we also given a single machine , which can do only single task at a time. we have
    to maximize the number of acitivities that we can perform on this single machine .

    The problem is machine can do only task at a time. So if we have activities with overlaping
    times , we can do only one task in them.

    for ex:
        I/p : {(2, 3), (1, 4), (5, 8), (6, 10)}
                |________|       |________|
                overlapping     overlapping
        O/p : 2 (we can do only two task , on this single tasking machine)

    Problem : Maximum no. of activities that can happen on a single tasking machine.
*/
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// sort by end time
bool sortByEnd(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return (p1.second < p2.second);
}

/* 
    finding maximum number of activities, we can do.
    time complexity : O(nlogn) -> sorting time
*/
int max_activity(int act_n, vector<pair<int, int>> act_arr)
{
    // sorting according to end time
    sort(act_arr.begin(), act_arr.end(), sortByEnd);

    vector<pair<int, int>> res;
    res.push_back(act_arr[0]); // always take first value of sorted act_arr in res

    // Do following for remaining activities
    for (int i = 1; i < act_n; i++)
    {
        pair<int, int> curr = act_arr[i];
        if (curr.first >= res.back().second)
            res.push_back(curr);
    }

    return res.size();
}

int main()
{
    // number of activities
    int act_n;
    cout << "\nEnter total number of activities : ";
    cin >> act_n;

    vector<pair<int, int>> act_arr;
    cout << "\nStart entering start & end timing of tasks : \n";
    for (int i = 0; i < act_n; i++)
    {
        cout << "\nfor task " << i + 1 << ": \n";
        int start_time, end_time;
        cout << "\nenter start time : ";
        cin >> start_time;
        cout << "\nenter end time : ";
        cin >> end_time;
        act_arr.push_back(make_pair(start_time, end_time));
        cout << endl;
    }

    int max_task = max_activity(act_n, act_arr);
    cout << "\nMaximum number of activities, we can do : " << max_task << endl;

    return 0;
}