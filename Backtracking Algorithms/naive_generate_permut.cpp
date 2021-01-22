/*
    naive approach of generating all permutation

    Problem : Given a string "ABC", generate all its permutations that do not
                contains "AB" as substring.
*/
#include <iostream>
#include <string>
#include <utility>
using namespace std;

// function generating all permutation of a string
void generate_permut(string str, int start_idx, int end_idx)
{
    if (start_idx == end_idx && (str.find("AB") == string::npos))
    {
        cout << str << ' ';
        return;
    }
    else
    {
        for (int i = start_idx; i <= end_idx; i++)
        {
            swap(str[i], str[start_idx]);
            generate_permut(str, start_idx + 1, end_idx);
            swap(str[i], str[start_idx]);
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