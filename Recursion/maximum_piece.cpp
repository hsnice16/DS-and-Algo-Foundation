/*
    Description : Given a rope of length n, you need to find maximum
    number of pieces you can make such that length of every piece is 
    in set {a, b, c} for given three values a, b and c.
*/

#include <iostream>
using namespace std;

// max function
int max(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
            return a;
        else
            return c;
    }
    return (b > c ? b : c);
}

// function finding maximum number of pieces of rope
int find_max_piece_num(int len, int a, int b, int c)
{
    if (len < 0)
        return -1;

    if (len == 0)
        return 0;

    int res = max(find_max_piece_num(len - a, a, b, c),
                  find_max_piece_num(len - b, a, b, c),
                  find_max_piece_num(len - c, a, b, c));

    if (res == -1)
        return -1;
    return res + 1;
}

int main()
{
    int len;
    cout << "\nenter length of the rope : ";
    cin >> len;

    int a, b, c;
    cout << "\nenter value of a : ";
    cin >> a;

    cout << "\nenter value of b : ";
    cin >> b;

    cout << "\nenter value of c : ";
    cin >> c;

    int piece_num = find_max_piece_num(len, a, b, c);
    cout << "\nMaximum number of piece of rope : " << piece_num;

    return 0;
}