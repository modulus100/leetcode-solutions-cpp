#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out(2);
        unordered_map<int, int> map;

         for (int i = 0; i < nums.size(); i++) {
             int diff = target - nums[i];

             if (map.count(diff)) {
                 out[0] = map[diff];
                 out[1] = i;
                 return out;
             } else {
                 map[nums[i]] = i;
             }
         }

        return out;
    }
};

int main() {
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(11);
    vec.push_back(15);

    Solution sln;
    sln.twoSum(vec, 0);

    return 0;
}