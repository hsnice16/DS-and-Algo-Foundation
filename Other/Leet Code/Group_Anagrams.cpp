#include <iostream>
#include <vector>
using namespace std;

bool check_anagram(string &str_1, string &str_2) {
    if (str_1.length() != str_2.length()) {
        return false;
    }

    int count[26] = {0}; // for 26 alphabets

    for (int i = 0; i < str_1.length(); i++) {
        count[str_1[i] - 'a']++;
        count[str_2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0)
            return false;
    }
    return true;
}

void print_res(vector<vector<string>> res) {
    for (int outer_index = 0; outer_index < res.size(); outer_index++) {
        for (int inner_index = 0; inner_index < res[outer_index].size(); inner_index++) {
            cout << res[outer_index][inner_index] << " ";
        }
        cout << endl;
    }
}

void groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    
    while(strs.size()) {
        int index = 1;
        
        vector<string> aux;
        aux.push_back(strs[0]);
        
        while(index < strs.size()) {
            if(check_anagram(strs[0], strs[index])) {
                aux.push_back(strs[index]);
                strs.erase(strs.begin() + index);
                index--;
            }    
            index++;
        }
        
        strs.erase(strs.begin());
        res.push_back(aux);
    }
    
    // return res;
    print_res(res);
}

int main() {
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };

    groupAnagrams(strs);

    return 0;
}