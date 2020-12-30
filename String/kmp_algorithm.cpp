/*
    KMP pattern searching algorithm
*/

#include <iostream>
#include <string>
using namespace std;

// function making lps
void make_lps(string &pttrn, int lps[])
{
    int len = 0;
    lps[0] = len;
    int i = 1;

    // filling lps
    while (i < pttrn.length())
    {
        if (pttrn[i] == pttrn[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = len;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

void KMPsearch(string &txt, string &pttrn)
{
    int txt_len = txt.length();
    int pttrn_len = pttrn.length();

    int lps[pttrn_len];
    make_lps(pttrn, lps);

    int i = 0, j = 0;
    bool present = false;
    while (i < txt_len)
    {
        if (pttrn[j] == txt[i])
        {
            j++;
            i++;    // moving ahead in text
        }

        if (j == pttrn_len)
        {
            present = true;
            cout << "\nPresent at index : " << i - j;
            j = lps[j - 1];     // sliding the pattern
        }
        else if (i < txt_len && pttrn[j] != txt[i])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }

    if (!present)
    {
        cout << "\nNot present.";
    }

    return;
}

int main()
{
    string txt;
    cout << "\nenter your text : ";
    cin >> txt;

    string pttrn;
    cout << "\nenter your pattern : ";
    cin >> pttrn;

    cout << "\nPattern in text : \n";
    KMPsearch(txt, pttrn);

    return 0;
}