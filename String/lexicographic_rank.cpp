/*
    given a string, find its lexicographic rank 

    Idea to count lexicographic rank of a given string :
        count lexicographic smaller strings + 1
*/

#include <iostream>
#include <string>
using namespace std;

constexpr int CHAR{256};

// finding factorial
int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

// function calculating lexicographic rank of string
int find_lexico_rank(string &str)
{
    int rank = 1;
    int len = str.length(); // string length
    int mul = fact(len);    // calculating factorial of whole length of string
    int count[CHAR] = {0};  // to store frequency of each char in string

    // count frequency
    for (int i = 0; i < len; i++)
    {
        count[str[i]]++;
    }

    // find commulative sum, so that we can know how many characters
    // are smaller than character at any index, in right of it.
    // we can find this, if char is at index i, of which we want to know
    // number of smaller character in right of it, then find value of str[i]-1
    // in count
    for (int i = 1; i < CHAR; i++)
    {
        count[i] += count[i - 1];
    }

    // find number of string lexicographic smaller than given string
    for (int i = 0; i < len - 1; i++)
    {
        mul = mul / (len - i);           // factorial of number of characters in right side after this index
        rank += count[str[i] - 1] * mul; // number of characters smaller than char at index i, on right side of it
        for (int j = str[i]; j < CHAR; j++)
            count[j]--; // decreasing count for right side of char of index i(including itself)
    }

    return rank;
}

int main()
{
    string str;
    cout << "\nenter your string : ";
    cin >> str;

    int lexico_rank = find_lexico_rank(str);
    cout << "\nLexicographic rank of string is : " << lexico_rank;

    return 0;
}