// program finding index of leftmost repeating character in given string

// works for lower case strings

#include <iostream>
#include <string>
using namespace std;

// function finding index of leftmost repeating character in given string
int find_repeating(string &str)
{
    /*
        Better Approach

        int count[26] = {0};

        for (int i = 0; i < str.length(); i++)
            count[str[i] - 'a']++;

        for (int i = 0; i < str.length(); i++)
        {
            if (count[str[i] - 'a'] > 1)
                return i;
        }
        return -1;
    */

    // efficient approach

    bool visited[26] = {false};
    int res = -1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (visited[str[i] - 'a'])
            res = i;
        else
            visited[str[i] - 'a'] = true;
    }

    return res;
}

int main()
{
    string str;
    cout << "\nenter string : ";
    cin >> str;

    cout << "\nIndex of leftmost repeating character : " << find_repeating(str);

    return 0;
}