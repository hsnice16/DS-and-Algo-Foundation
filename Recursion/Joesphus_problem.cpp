// Josephus Problem Implementation

#include <iostream>
using namespace std;

int solve_josephus(int n, int k)
{
    if(n==1)
        return 1;
    return ((solve_josephus(n-1, k) + (k-1))%n + 1);
}

int main()
{
    int n = 5;
    int k = 2;

    cout << "\nI will choose place " << solve_josephus(n , k) ;

    return 0;
}