// Internal works using hashing, no order of keys, store key-value pair

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> um; // key is string, value is integer
    um["gfg"] = 20;
    um["ide"] = 30;
    um.insert({"courses", 15});

    for (auto x : um)
        cout << x.first << " " << x.second << endl;

    cout << "\nCheck key \"gfg\" is present or not : ";
    if (um.find("gfg") != um.end())
        cout << "\nPresent";
    else
        cout << "\nNot Present";

    return 0;
}