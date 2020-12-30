// program , checking any permutation of given pattern
// is present in the given text or not

#include <iostream>
#include <string>

#define CHAR 256

using namespace std;

bool areSame(int txt_arr[], int pttrn_arr[])
{
    for (int i = 0; i < CHAR; i++)
    {
        if (txt_arr[i] != pttrn_arr[i])
            return false;
    }
    return true;
}

bool permut_present(string &txt, string &pttrn)
{
    int txt_arr[CHAR] = {0};
    int pttrn_arr[CHAR] = {0};

    for (int i = 0; i < pttrn.length(); i++)
    {
        txt_arr[txt[i]]++; // first window of text
        pttrn_arr[pttrn[i]]++;
    }

    for (int i = pttrn.length(); i < CHAR; i++)
    {
        if (areSame(txt_arr, pttrn_arr))
            return true;

        txt_arr[txt[i - pttrn.length()]]--; // sliding the window, by removing the
                                            // first element of previous window
        txt_arr[txt[i]]++;                  // adding new value of new window
    }

    return false;
}

int main()
{
    string txt;
    cout << "\nenter your text : ";
    cin >> txt;

    string pttrn;
    cout << "\nenter your pattern : ";
    cin >> pttrn;

    if (permut_present(txt, pttrn))
        cout << "\nPermutation of pattern is present in text.";
    else
        cout << "\nPermutation of pattern is not present in text.";

    return 0;
}