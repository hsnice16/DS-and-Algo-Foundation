// program finding sum of digits of a number

#include <iostream>
using namespace std;

// function finding sum of digits
int find_digit_sum(int num, int sum = 0)
{
    if (num == 0)
        return sum;
    return find_digit_sum(num / 10, sum + num % 10);

    /*
            OR

        if (num < 10)
            return num;
        return find_digit_sum(num / 10) + num % 10;
    */
}

int main()
{
    int num;
    cout << "\nenter your number : ";
    cin >> num;

    int digit_sum = find_digit_sum(num);
    cout << "\nSum of digits : " << digit_sum;

    return 0;
}