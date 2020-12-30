// naive approach to search a pattern in given text

#include <iostream>
#include <string>
using namespace std;

// naive approach
void srch_pattrn(string &txt, string &pattrn)
{
    bool present = false;
    int txt_len = txt.length();
    int pttrn_len = pattrn.length();

    for (int i = 0; i <= txt_len - pttrn_len; i++)
    {
        int j;
        for (j = 0; j < pttrn_len; j++)
        {
            if (pattrn[j] != txt[i + j])
                break;
        }

        if (j == pttrn_len)
        {
            present = true;
            cout << "\nPresent at index : " << i;
        }
    }
    if (!present)
        cout << "\nPattern is not present in string !!";
}

int main()
{
    string txt;
    cout << "\nenter your text : ";
    cin >> txt;

    string pattrn;
    cout << "\nenter pattern : ";
    cin >> pattrn;

    srch_pattrn(txt, pattrn);

    return 0;
}