// finding square root, using binary search

#include <iostream>
using namespace std;

// function finding pefect square root of num, if
// exists, otherwise floor of square root
int find_square_root(int num)
{
    int low = 1, high = num, ans;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        int sq_val = mid * mid;

        if (sq_val == num)
            return mid;
        else if (sq_val > num)
            high = mid - 1;
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }

    return ans;
}

int main()
{
    int num;
    cout << "\nenter number whose square to find: ";
    cin >> num;         // should > 0

    int sq_root = find_square_root(num);

    cout << "\nsquare root(or floor of square root) : " << sq_root;

    return 0;
}