/*
    Solving weighted interval scheduling problem in C++

    Problem Description: 
        Given a set of n intervals (si, fi), each with a value vi, 
        choose a subset S of non-overlapping intervals with Σ(i∈S)vi maximized.  

    Algo:
        OPT(j) = the optimal solution considering only intervals 1, ..., j/

        OPT(j) = max { vj + OPT(p(j)),   j in OPT solution
                        OPT(j − 1),      j not in solution
                        0,               j = 0 }

        p(j) is the interval farthest to the right that is compatible with j.
        And by compatible we mean non-overlapping

    Idea:
        -: use DP
        -: Sort the array according to finish time and apply algo
*/

#include <algorithm>    // sort
#include <iostream>
#include <vector>
using namespace std;

struct interval {
    int start_time;
    int finish_time;
    int value;

    interval(int s, int f, int v)
    {
        this->start_time = s;
        this->finish_time = f;
        this->value = v;
    }
};

int weighted_interval_scheduling(vector<interval> inter_arr, int intervals
);
bool sortBy(struct interval interval1, struct interval interval2);
int latestNonConflicting(vector<interval> inter_arr, int j);

int main() 
{
    int intervals = 0;
    cout << "\nEnter total numbers of interval: ";
    cin >> intervals;

    // storing (start_time, finish_time, value) for each interval
    vector<interval> inter_arr;
    cout << "\nStart entering: start_time finish_time value\n";
    for(int i=0; i<intervals; i++){
        int s, f, v;
        cin >> s >> f >> v;

        inter_arr.push_back(interval(s, f, v));
    }

    int max_val = weighted_interval_scheduling(inter_arr, intervals);
    cout << "\nMaximum Value: " << max_val << endl;

    return 0;
}

int weighted_interval_scheduling(vector<interval> inter_arr, int intervals)
{
    // sorting by increasing order of finish time
    sort(inter_arr.begin(), inter_arr.end(), sortBy);   

    int OPT[intervals + 1];
    OPT[0] = 0;

    for (int j=1; j <= intervals; j++) {
        int val = inter_arr[j-1].value;
        int non_conflict = latestNonConflicting(inter_arr, j-1);
        
        val += non_conflict != -1 ? OPT[non_conflict+1] : 0;

        OPT[j] = max(val, OPT[j-1]); 
    }   

    return OPT[intervals];
}

bool sortBy(struct interval interval1, struct interval interval2)
{
    return interval1.finish_time < interval2.finish_time;
}

int latestNonConflicting(vector<interval> inter_arr, int j) 
{

    for (int i=j-1; i>=0; i--)
    {
        if(inter_arr[i].finish_time <= inter_arr[j].start_time) {
            return i;
        }
    }
    return -1;
}