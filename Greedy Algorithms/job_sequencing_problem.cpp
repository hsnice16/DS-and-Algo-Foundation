/*
    I/P:
                    J_0   J_1  J_2  J_3
        ---------------------------------
       | deadline | 4   | 1  | 1  | 1   |
       | profit   | 70  | 80 | 30 | 100 |
        ---------------------------------

    we have given n jobs, in above we have given job J_0, J_1, J_2 and J_3.
    Every job has a deadline and every job has a profit associated with it.
    we will get the profit, if we finish the job by the given deadline.
    
    Problem : maximize the profit.

    Rules :
        - every job take one unit of time
        - only one job can be assigned at a time
        - time starts with 0
*/
#include <algorithm>
#include <iostream>
using namespace std;

struct Job
{
    int deadline;
    int profit;
};

// sort in descending order by profit
bool sortByprofit(struct Job &j1, struct Job &j2)
{
    return (j1.profit > j2.profit);
}

// find maximum deadline
int max_deadline(struct Job arr[], int ttl_job)
{
    int max = 0;
    for (int i = 0; i < ttl_job; i++)
    {
        if (arr[i].deadline > max)
            max = arr[i].deadline;
    }
    return max;
}

// function finding maximum profit, we can make
int find_max_profit(struct Job arr[], int ttl_job)
{
    // sort the array in decreasing order of profit
    sort(arr, arr + ttl_job, sortByprofit);

    // maximum deadline
    int max_dead = max_deadline(arr, ttl_job);

    // make slots equal to maximum deadline
    int res[max_dead] = {0};

    // Iterate through all the given jobs
    for (int i = 0; i < ttl_job; i++)
    {
        for (int j = (arr[i].deadline - 1); j >= 0; j--)
        {
            if (res[j] == 0)
            {
                res[j] = arr[i].profit; // add to last possible slot
                break;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < max_dead; i++)
        sum += res[i];

    return sum;
}

int main()
{
    // total number of jobs
    int ttl_job;
    cout << "\nEnter number of jobs : ";
    cin >> ttl_job;

    struct Job arr[ttl_job]; // job array
    cout << "\nStart entering deadline and profit for each job : \n";
    for (int i = 0; i < ttl_job; i++)
    {
        cout << "For job " << i + 1 << " : \n";
        cout << "Enter deadline : ";
        cin >> arr[i].deadline;
        cout << "Enter profit : ";
        cin >> arr[i].profit;
        cout << '\n';
    }

    int max_profit = find_max_profit(arr, ttl_job);
    cout << "\nMaximum profit we can make : " << max_profit;

    return 0;
};