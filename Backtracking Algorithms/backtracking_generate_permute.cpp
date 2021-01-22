/*
    In Backtracking approach, we don't just generate all the permutations
    and then check.
    We cut down the recursion , whenever we feel like that "AB" is gonna
    to form in our string .

    Idea : put some condition ,before making recursive call.

    In naive approach, we are doing n! * n work, but in backtracking we will
    reduce some amount of n! work
*/
#include <iostream>
#include <string>
#include <utility>
using namespace std;

// checking string contains "AB" or not
bool isSafe(string str, int start_idx, int i, int end_idx)
{
    if (start_idx != 0 && str[start_idx - 1] == 'A' && str[i] == 'B')
        return false;

    if (end_idx == (start_idx + 1) && str[i] == 'A' && str[start_idx] == 'B')
        return false;

    return true;
}

// function generating all permutation of a string
void generate_permut(string str, int start_idx, int end_idx)
{
    if (start_idx == end_idx)
    {
        cout << str << ' ';
        return;
    }
    else
    {
        for (int i = start_idx; i <= end_idx; i++)
        {
            if (isSafe(str, start_idx, i, end_idx))
            {
                swap(str[i], str[start_idx]);
                generate_permut(str, start_idx + 1, end_idx);
                swap(str[i], str[start_idx]);
            }
        }
    }
}

int main()
{
    string str = "ABC";
    int start_idx = 0;
    int end_idx = 2;
    generate_permut(str, start_idx, end_idx);
    return 0;
}