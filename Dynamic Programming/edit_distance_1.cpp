/*
    Implementation of Edit Distance Problem

    Problem : given two strings s1 and s2 , we need to convert s1 into s2, we are
            allow to insert, delete and replace operation.
            Do conversion with minimum number of operations.
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// function counting minimum number of operation required
int count_opr(string s1, string s2, int s1_len, int s2_len)
{
    if (s1_len == 0)
        return s2_len;
    if (s2_len == 0)
        return s1_len;

    if (s1[s1_len - 1] == s2[s2_len - 1])
    {
        return count_opr(s1, s2, s1_len - 1, s2_len - 1);
    }
    else
    {
        /*
            3 recursive call 
            first considering delete operation, 
            second considering insert operation,
            third considering replace operation
        */
        return 1 + min(count_opr(s1, s2, s1_len - 1, s2_len),
                       min(
                           count_opr(s1, s2, s1_len, s2_len - 1),
                           count_opr(s1, s2, s1_len - 1, s2_len - 1)));
    }
}

int main()
{
    string s1, s2;
    cout << "\nEnter first string : ";
    cin >> s1;
    cout << "\nEnter second string : ";
    cin >> s2;

    int s1_len = s1.length(), s2_len = s2.length();
    cout << "\nMinimum number of operations required : " << count_opr(s1, s2, s1_len, s2_len);

    return 0;
}