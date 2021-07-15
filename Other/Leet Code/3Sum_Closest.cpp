#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {

    sort(nums.begin(),nums.end()); //-4 -1 1 2
    int n=nums.size(); //4
    int sum=INT_MAX; 

    for(int i=0;i<n;i++){

        int after_i=i+1; int last_i=n-1;

        while(after_i<last_i){

            int here=nums[i]+nums[after_i]+nums[last_i];

            if(here==target){
                sum=target;
                return sum;
            }

            if(abs(target-here)<abs(sum)) sum=target-here;

            if(here>target) last_i--;
            else after_i++;
        }
    }
    return target-sum;
}

int main() {

    vector<int> input = { 1, 2, 4, 8, 16, 32, 64, 128 };
    int target = 82;

    cout << threeSumClosest(input, target);
    return 0;
}