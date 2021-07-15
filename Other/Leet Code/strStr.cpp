#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    if(needle.length() == 0){
        return 0;
    }   
    
    int haystackLength = haystack.length();
    int needleLength = needle.length();

    for (int i=0; i<= (haystackLength - needleLength); i++) {
        int j;

        for (j = 0; j<needleLength; j++) {
            if(needle[j] != haystack[i+j]) {
                break;
            }
        }

        if(j == needleLength) {
            return i;
        }
    }

    return -1;
}

int main() {
    string haystack = "hello";
    string needle = "ll";

    cout << strStr(haystack, needle);
    return 0;
}