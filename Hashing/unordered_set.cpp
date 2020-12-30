// Internal implementation of unordered_set in stl is based on hashing

#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> us;
    us.insert(10);
    us.insert(5);
    us.insert(15);
    us.insert(20);

    for (int x : us)
        cout << x << " "; // can print in order
    cout << endl;

    cout << "\nSize : " << us.size();

    cout << "\nFind 15 present or not : ";
    if (us.find(15) == us.end())
        cout << "\nNot Present";
    else
        cout << "\nPresent";

    /*
        // can be use as substitute of find
        if(us.count(15))    // count returns 0 or 1(set, no duplicate)
            cout << "Present";
        else
            cout << "Not Present";
    */

    us.erase(15); // erase using value
    cout << "\nAfter erasing 15 , Size : " << us.size();

    us.erase(us.find(10)); // erase using iterator
    cout << "\nAfter erasing 10, Size : " << us.size();

    us.erase(us.begin(), us.end()); // erase using range, [us.begin(), us.end())
    cout << "\nAfter erasing using range, Size : " << us.size();

    us.clear();
    cout << "\nAfter Clearing Size : " << us.size();

    return 0;
}