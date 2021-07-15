#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void possible_permute(vector<vector<int>> &res, vector<int>& nums, int start_idx) {
    
    if(start_idx == nums.size() - 1) {
        res.push_back(nums);
        return;
    }
    
    for (int idx = start_idx; idx < nums.size(); idx++) {
        swap(nums[idx], nums[start_idx]);
        possible_permute(res, nums, start_idx + 1);
        swap(nums[idx], nums[start_idx]);
    }
}
    
void permute(vector<int>& nums) {
    vector<vector<int>> res;
    
    possible_permute(res, nums, 0);

    for (int outer_index = 0; outer_index < res.size(); outer_index++) {
        for (int inner_index = 0; inner_index < res[outer_index].size(); inner_index++) {
            cout << res[outer_index][inner_index] << " ";
        }
        cout << endl;
    }

    // return res;
}

int main() {
    vector<int> nums = {1, 2, 3};

    permute(nums);

    return 0;
}