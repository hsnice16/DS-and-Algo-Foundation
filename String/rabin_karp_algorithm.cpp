/*
    Rabin Kar Algorithm for pattern searching in string.
    Using Improved Rolling Hash
        t_0 = a_1 * d ^ m-1 + ... + a_m * d ^ m-m
        t_n = d * (t_(n-1) - a_(n-1) * d ^ m-1) + a_n

    where , m is the length of pattern
*/
#include <iostream>
#include <string>
using namespace std;

void RBSearch(string txt, string pttrn)
{
    int txt_len = txt.length();
    int pttrn_len = pttrn.length();

    int d = 10;  // d used to minimize spurious hit (weighted sum)
    int q = 111; // generally a prime
    int h = 1;   // for storing d^(m-1)
    // calculation d^(m-1)
    for (int i = 1; i <= (pttrn_len - 1); i++)
    {
        h = (h * d) % q; // q used so that for large hash,it can store in int
    }

    int p = 0, t = 0;
    // calculating hash value of pattern and first set of text
    for (int i = 0; i < pttrn_len; i++)
    {
        p = (p * d + pttrn[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    bool present = false;

    // comparing each hash value of possible set of text with pattern
    for (int i = 0; i <= txt_len - pttrn_len; i++)
    {
        if (p == t) // if hash value of current set of text equal to hash value of pttrn
        {
            bool flag = true;
            for (int j = 0; j < pttrn_len; j++)
            {
                if (pttrn[j] != txt[i + j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                present = true;
                cout << "\nPresent at Index : " << i;
            }
        }

        if (i < txt_len - pttrn_len) // not include last set
        {
            t = (d * (t - txt[i] * h) + txt[i + pttrn_len]) % q; // computing hash of next set
            if (t < 0)                                           // hash should not be negative, as we are comparing (p==t)
                t = t + q;
        }
    }

    if(!present)
        cout << "\nNot Present.";
}

int main()
{
    string txt; // text string
    cout << "\nenter text : ";
    cin >> txt;

    string pttrn; // pattern string
    cout << "\nenter pattern : ";
    cin >> pttrn;

    RBSearch(txt, pttrn);

    return 0;
}