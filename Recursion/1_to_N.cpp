// program prints numbers from 1 to N using recursion

#include <iostream>
using namespace std;

void print(int n)
{
    if (n <= 0)
        return;
    print(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cout << "\nenter value of n : ";
    cin >> n;

    print(n); // will print from 1 to N

    return 0;
}