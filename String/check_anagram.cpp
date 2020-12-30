// program checking two given string are anagrams of each other or not

// this will work for only lower case strings

#include <iostream>
#include <string>
using namespace std;

// function checking two strings are anagrams of each other or not
bool check_anagram(string &str_1, string &str_2)
{
    if (str_1.length() != str_2.length())
    {
        return false;
    }

    int count[26] = {0}; // for 26 alphabets

    for (int i = 0; i < str_1.length(); i++)
    {
        count[str_1[i] - 'a']++;
        count[str_2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string str_1, str_2;
    cout << "\nenter first string : ";
    cin >> str_1;

    cout << "\nenter second string : ";
    cin >> str_2;

    if (check_anagram(str_1, str_2))
    {
        cout << "\nBoth strings are anagrams of each other !!";
    }
    else
    {
        cout << "\nBoth strings are not anagrams of each other !!";
    }

    return 0;
}