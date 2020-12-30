// program finding all subset or subsection of a given string

#include <iostream>
using namespace std;

void print_sub_sec(string str, string sub = "", int n = 0)
{
    if (n == str.length())
    {
        cout << sub << " ";
        return;
    }

    print_sub_sec(str, sub, n + 1);
    print_sub_sec(str, sub + str[n], n + 1);
}

int main()
{
    string str;
    cout << "\nenter your string : ";
    cin >> str;

    print_sub_sec(str);
    return 0;
}