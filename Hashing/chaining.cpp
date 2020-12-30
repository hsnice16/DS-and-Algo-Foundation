/*
    Chaining, a way to handle collision in hashing

    Some Notes : 
    if, m = number of slots in hash table
        n = number of keys to be inserted

    then, 
        load factor (probability of collision) (alpha) = n/m
    and, 
        expected chain length = alpha
        expected time to search/ insert/ delete = O(1 + alpha)
*/

// Implementation of chaingin using linked list

#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

class MyHash
{
private:
    int SLOTS;        // number of slots
    list<int> *table; // list , perform doubly linked list
public:
    MyHash(int slot)
    {
        SLOTS = slot;
        table = new list<int>[slot]; // array of list
    }
    void insert(int key);
    bool search(int key);
    void remove(int key);
};

void MyHash::insert(int key)
{
    int i = key % SLOTS; // working as hash function
    table[i].push_back(key);
}

void MyHash::remove(int key)
{
    int i = key % SLOTS;
    table[i].remove(key);
}

bool MyHash::search(int key)
{
    int i = key % SLOTS;
    if (find(table[i].begin(), table[i].end(), key) != table[i].end())
        return true;
    return false;

    /*
        int i = key % SLOTS;
        for(auto x : table[i])
            if(x == key)
                return true;
        return false;
    */
}

int main()
{

    int slot_num;
    cout << "\nenter number of slots in hash table you want : ";
    cin >> slot_num;

    MyHash my_hash(slot_num);

    int key_num;
    cout << "\nenter number of keys, you want to enter : ";
    cin >> key_num;
    cout << "\nStart entering key values : \n";
    for (int i = 0; i < key_num; i++)
    {
        int temp;
        cout << i + 1 << "). ";
        cin >> temp;
        my_hash.insert(temp);
    }

    int srch_val;
    cout << "\nenter value you want to search : ";
    cin >> srch_val;

    if (my_hash.search(srch_val))
        cout << "\nValue is present !!";
    else
        cout << "\nValue is not present !!";

    return 0;
}