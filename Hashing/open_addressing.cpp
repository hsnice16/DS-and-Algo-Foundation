/*
    Open Addressing, another way to handle collision in hashing

    Some info:
        1) in open addressing , number of slots in hash table >= number of keys
        2) it is cache friendly

    linear probing : linearly search for next empty slot, when there is collision
    Primary Clustering : a problem in linear probing, happen when collision occur

    In linear probing, for ith time, hash function is like
        hash(key, i) = (h(key) + i) % m, 

        where, m is number of slots in hash table
               h(key) is key % m

    In Quadratic probing, for ith time, hash function is like
        hash(key, i) = (h(key) + i^2) % m

    quadratic probing has problem of secondary clustering

    In Double Hashing, for ith time, hash function is like
        hash(key, i) = (h1(key) + i*h2(key)) % m

        where, h1(key) = key % m
               h2(key) = (m-1) - key % (m-1), this should never return zero

               h2(key) should be relatively prime with m, 

    all hash(key, i) type function is used, when collision happens, otherwise we
    use , our normal hash function, h(key) = key % m

    expected time to search = O(1 / (1 - alpha))
*/

/*
    Simple Implementation of Open Addressing
    ASSUMPTION : 

    -1, -2 are not present in key
    -1 represents empty slot
    -2 represents deleted slot
*/

#include <iostream>
using namespace std;

class MyHash
{
private:
    int *hash;
    int capacity, size;

public:
    MyHash(int capacity)
    {
        this->capacity = capacity;
        size = 0; // initially hash is empty
        hash = new int[capacity];
        for (int i = 0; i < capacity; i++)
            hash[i] = -1;
    }
    int hash_func(int key)
    {
        return key % capacity;
    }
    bool search(int key);
    bool insert(int key); // unsuccessfull insert , if size is full or key is already present
    bool remove(int key); // unsuccessfull remove, if value is not present or hash table is empty
};

bool MyHash::search(int key)
{
    int h = hash_func(key);
    int i = h;
    while (hash[i] != -1)
    {
        if (hash[i] == key)
            return true;
        i = (i + 1) % capacity; // linear probing
        if (i == h)             // if we traversed whole array
            return false;
    }

    return false;
}

bool MyHash::insert(int key)
{
    if (size == capacity)
        return false;

    int h = hash_func(key);

    while (hash[h] != -1 && hash[h] != -2 && hash[h] != key)
        h = (h + 1) % capacity;

    if (hash[h] == key)
        return false;
    else
    {
        hash[h] = key;
        size++;
    }
    return true;
}

bool MyHash::remove(int key)
{
    if (size == 0)
        return false;

    int h = hash_func(key);
    int i = h;
    while (hash[i] != -1)
    {
        if (hash[i] == key)
        {
            hash[i] = -2;
            return true;
        }
        i = (i + 1) % capacity;
        if (i == h)
            return false;
    }
    return false;
}

int main()
{
    MyHash mh(7);
    mh.insert(49);
    mh.insert(56);
    mh.insert(72);
    if (mh.search(56))
        cout << "\nPresent";
    else
        cout << "\nNot Present";
    mh.remove(56);
    if (mh.search(56))
        cout << "\nPresent";
    else
        cout << "\nNot Present";

    return 0;
}