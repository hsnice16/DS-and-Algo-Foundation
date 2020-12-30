// program finding sum of first n natural number using recursion

#include <iostream>
using namespace std;

// finding sum
int natural_num_sum(int n, int sum = 0)
{
    if (n == 0)
        return sum;
    return natural_num_sum(n - 1, sum + n);
}

int main()
{
    int n;
    cout << "\nSum of How many natural number terms you want ?(enter): ";
    cin >> n;

    cout << "\nSum of first " << n << " natural number terms : " << natural_num_sum(n);

    return 0;
}