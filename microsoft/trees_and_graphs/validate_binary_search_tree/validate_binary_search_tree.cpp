
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
    cout << "test" << endl;

    return 0;
}