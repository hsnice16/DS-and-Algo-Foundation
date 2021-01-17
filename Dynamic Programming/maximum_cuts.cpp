/*
    DP version of maximum pieces program in Recursion directory
*/
#include <algorithm>
#include <iostream>
using namespace std;

// function finding maximum number of pieces of rope
int find_max_piece_num(int len, int a, int b, int c)
{
    int table[len + 1];
    table[0] = 0; // when len = 0

    for (int i = 1; i <= len; i++)
    {
        table[i] = -1;
        if (i - a >= 0)
            table[i] = max(table[i], table[i - a]);
        if (i - b >= 0)
            table[i] = max(table[i], table[i - b]);
        if (i - c >= 0)
            table[i] = max(table[i], table[i - c]);

        if (table[i] != -1)
            table[i]++;
    }

    return table[len];
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