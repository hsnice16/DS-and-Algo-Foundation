// program checking given string is a palindrome or not

#include <iostream>
#include <string>
using namespace std;

// checking palindrome or not
bool check_palindrome(string str, int start_ind, int end_ind)
{
    if(end_ind <= start_ind)
        return true;
/*
    else if (str[start_ind] != str[end_ind])
        return false;
    return check_palindrome(str, ++start_ind, --end_ind);
*/
    return (str[start_ind] == str[end_ind] && 
    check_palindrome(str, ++start_ind, --end_ind));
}

int main()
{
    string str;
    cout << "\nenter data to check palindrome : ";
    getline(cin, str);

    int start_ind = 0;
    int end_ind = str.length()-1;

    if(check_palindrome(str, start_ind, end_ind))
        cout << "\nYour data is palindrome !!" ;
    else
        cout << "\nNo, Your data is not palindrome !!";

    return 0;
}