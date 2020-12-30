/*
    Longest Proper Prefix Suffix Array (longest proper prefix which is also a suffix)
    , a pre-requistie for KMP pattern searching
    algorithm

    Proper prefix of "abc"(should always be less than total length of pattern)
    "", "a", "ab"

    Proper suffix of "abc"
    "", "c", "bc", "abc"

    for ex :
    string : "ababc"
    lps[] = {0, 0, 1, 2, 0}

    Dry Run:
    for first entry , 'a', longest proper prefix which is also suffix is "" .
    so length of lps is 0.

    for second entry, 'ab', longest proper prefix which is also suffix is "",
    so length of lps is 0.

    for third entry, 'abc', longest proper prefix which is also suffix is 'a',
    so length of lps is 1.

    and so on
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    Naive Approach, taking O(n^3) time

// function filling lps
int fill_lps(string &str, int n)
{
    for (int len = n - 1; len > 0; len--)
    {
        bool flag = true;
        for (int i = 0; i < len; i++)
        {
            if (str[i] != str[n - len + i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return len;
    }
    return 0;
}

// function making lps
void make_lps(string &str, vector<int> &lps)
{
    for (int i = 0; i < str.length(); i++)
    {
        lps.push_back(fill_lps(str, i + 1));
    }
}
*/

/*
    efficient solution, taking O(n) time

    Basic Idea: 
    1)  if len = lps[i-1] and str[len] == str[i], then lps[i] = lps[i-1]+1

    2) if str[i] != str[len] , then

    (i) if len == 0, then lps[i] = 0;
    (ii) else when len is not 0, we recursively apply lps[], len = lps[len-1]
        then compares str[i] with str[len]
*/

void make_lps(string str, vector<int> &lps)
{
    int len = 0;
    lps.push_back(len);
    int i = 1;

    // filling lps
    while (i < str.length())
    {
        if (str[i] == str[len])
        {
            len++;
            lps.push_back(len);
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps.push_back(len);
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

int main()
{
    string str;
    cout << "\nenter your string : ";
    cin >> str;

    vector<int> lps;
    make_lps(str, lps);

    cout << "\nLPS array : ";
    for (int i = 0; i < lps.size(); i++)
        cout << lps[i] << ' ';

    return 0;
}