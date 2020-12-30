// program checking given string is palindrome

#include <iostream>
#include <string>
using namespace std;

// function checking palindrome or not
bool check_palindrome(const string &str)
{
    int start = 0;              // left most index
    int end = str.length() - 1; // right most index

    while (start < end)
    {
        if (str[start] != str[end])
            return false;

        start++;
        end--;
    }
    return true;
}

int main()
{
    string str;

    cout << "\nenter your string : ";
    cin >> str;

    if (check_palindrome(str))
        cout << "\nYour string is palindrome !!";
    else
        cout << "\nYour string is not palindrome !!";

    return 0;
}