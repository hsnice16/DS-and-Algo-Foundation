// tower of hanoi implementation

#include <iostream>
using namespace std;

void solve_hanoi(int disk_num, char from = 'A', char use = 'B', char to = 'C')
{
    if (disk_num == 1)
    {
        cout << "\nMove disk " << disk_num << " from " << from << " to " << to;
        return;
    }

    solve_hanoi(disk_num - 1, from, to, use);
    cout << "\nMove disk " << disk_num << " from " << from << " to " << to;
    solve_hanoi(disk_num - 1, use, from, to);
}

int main()
{
    int disk_num;
    cout << "\nenter number of total disk : ";
    cin >> disk_num;

    solve_hanoi(disk_num);

    return 0;
}