/*
    Program to find index of leftmost non repeating 
    character in given string
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

#define CHAR 256

// function finding left most non repeating character in given string
int find_non_repeating(string &str)
{
    int not_visited[CHAR]; // ascii 256 character

    // initially -1 stands for char is not present in string
    fill(not_visited, not_visited+CHAR, -1);    // initialize every element value of array with -1

    int res = numeric_limits<int>::max(); // result index

    for (int i = 0; i < str.length(); i++)
    {
        if (not_visited[str[i]] == -1)
        {
            not_visited[str[i]] = i;
        }
        else
        {
            not_visited[str[i]] = -2; // char present more than one time
        }
    }

    for (int i = 0; i < CHAR; i++)
    {
        if (not_visited[i] >= 0)
        {
            res = min(not_visited[i], res);
        }
    }

    return (res == numeric_limits<int>::max()) ? -1 : res;
}

int main()
{
    string str;
    cout << "\nenter your string : ";
    cin >> str;

    int ind = find_non_repeating(str);
    cout << "\nIndex of left most non repeating character : " << ind;
    cout << endl;
    return 0;
}