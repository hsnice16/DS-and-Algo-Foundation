// program  , Is second given string a rotation of given first string or not ?

#include <iostream>
#include <string>

using namespace std;

// checking second string is a rotation of first string or not
bool isRotate(string first, string second)
{
    if (first.length() != second.length())
        return false;

    return ((first + first).find(second) != string::npos);
}

int main()
{
    string first;
    cout << "\nenter your first string : ";
    cin >> first;

    string second;
    cout << "\nenter your second string : ";
    cin >> second;

    if (isRotate(first, second))
        cout << "\nSecond string is a rotation of First string .";
    else
        cout << "\nSecond string is not a rotation of First string .";

    return 0;
}