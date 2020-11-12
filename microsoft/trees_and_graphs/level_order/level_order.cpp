#include <iostream>
#include <vector>
#include "../../../shared/tree_node.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;

        if (root == nullptr) return vec;
        return vec;
    }
};


int main() {
    Solution sln;
    TreeNode node;
    node.val = INT_MAX;
    auto result = sln.levelOrder(&node);
    return 0;
}

