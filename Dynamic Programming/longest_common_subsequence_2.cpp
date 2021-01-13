/*
    Implementation based on tabulation implementation
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int lcs(string s1, string s2)
{
    int s1_len = s1.length();
    int s2_len = s2.length();
    /*  
        row and column one more than strings length, so we
        can handle case for 0 length string
    */
    int table[s1_len + 1][s2_len + 1];

    // initializing the first row with 0 (0 length string)
    for (int i = 0; i <= s2_len; i++)
        table[0][i] = 0;

    // initializing the first column with 0
    for (int i = 0; i <= s1_len; i++)
        table[i][0] = 0;

    // filling the table
    for (int i = 1; i <= s1_len; i++)
        for (int j = 1; j <= s2_len; j++)
            if(s1[i-1] == s2[j-1])
                table[i][j] = 1 + table[i-1][j-1];
            else
                table[i][j] = max(table[i-1][j],table[i][j-1]);            

    return table[s1_len][s2_len];
}

int main()
{
    string s1, s2;
    cout << "\nEnter your first string : ";
    cin >> s1;

    cout << "\nEnter your second string : ";
    cin >> s2;

    cout << "\nLength of longest common subsequence : "
         << lcs(s1, s2);

    return 0;
}