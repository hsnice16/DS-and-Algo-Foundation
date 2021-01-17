#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// function counting minimum number of operation required
int count_opr(string s1, string s2)
{
    int s1_len = s1.length();
    int s2_len = s2.length();
    int table[s1_len + 1][s2_len + 1];

    /*
        table[i][j] : Edit distance for s1[0,..,i-1] and s2[0,..,j-1]
    */

    // initializing first row, when s1_len == 0
    for (int i = 0; i <= s2_len; i++)
        table[0][i] = i;

    // initializing first column, when s2_len == 0
    for (int i = 0; i <= s1_len; i++)
        table[i][0] = i;

    for (int i = 1; i <= s1_len; i++)
    {
        for (int j = 1; j <= s2_len; j++)
        {

            if (s1[i] == s2[j])
            {
                table[i][j] = table[i - 1][j - 1];
            }
            else
            {
                table[i][j] = 1 + min({table[i - 1][j],
                                       table[i][j - 1],
                                       table[i - 1][j - 1]});
            }
        }
    }
    return table[s1_len][s2_len];
}

int main()
{
    string s1, s2;
    cout << "\nEnter first string : ";
    cin >> s1;
    cout << "\nEnter second string : ";
    cin >> s2;

    cout << "\nMinimum number of operations required : " << count_opr(s1, s2);

    return 0;
}