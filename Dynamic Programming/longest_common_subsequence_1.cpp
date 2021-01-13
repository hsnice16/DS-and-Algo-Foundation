/*
    Implementation of Longest Common Subsequence problem based on
    memoization implementation.
    
    What is a Subsequence ? of a string , can be obtained by taking 0
    or more char which may not be contiguous from string , and they 
    should be picked in same order.
    
    Like :  "CDA"-> "", "C", "D", "A", "CD", "CA", "DA", "CDA"
            "DBA"-> "", "D", "B", "A", "DB", "DA", "BA", "DBA"

    For length of string n, 2^n subsequence are possible.

    Problem : find length of longest common subsequence in two strings
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    function finding length of longest common subsequence

    Idea : let s1 = "AXYZ", s2 = "BAZ", then we recursively call for 1 + lps(s1,s2, s1_len-1,s2_len-2)
            and s1 = "AXY", s2 = "BA", then max(lps(s1,s2,s1_len-1,s2),
                                                lps(s1,s2,s1_len,s2_len-1))

            **see last character

    Time complexity : theta(s1_len*s2_len)
*/
int lcs(string s1, string s2, int s1_len, int s2_len, vector<vector<int>> memo)
{
    if (memo[s1_len][s2_len] != -1) // already encounter with this length
        return memo[s1_len][s2_len];

    if (s1_len == 0 || s2_len == 0)
        memo[s1_len][s2_len] = 0;
    else
    {
        if (s1[s1_len - 1] == s2[s2_len - 1])
            memo[s1_len][s2_len] = 1 + lcs(s1, s2, s1_len - 1, s2_len - 1, memo);
        else
            memo[s1_len][s2_len] = max(lcs(s1, s2, s1_len - 1, s2_len, memo),
                                       lcs(s1, s2, s1_len, s2_len - 1, memo));
    }
    return memo[s1_len][s2_len];
}

int main()
{
    string s1, s2;
    cout << "\nEnter your first string : ";
    cin >> s1;

    cout << "\nEnter your second string : ";
    cin >> s2;

    // initialize vector of vectors with -1;
    vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, -1));

    cout << "\nLength of longest common subsequence : "
         << lcs(s1, s2, s1.length(), s2.length(), memo);

    return 0;
}