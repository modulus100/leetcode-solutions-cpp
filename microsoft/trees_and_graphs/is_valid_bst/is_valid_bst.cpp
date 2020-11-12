#include <iostream>
#include <functional>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* node, long min, long max) {
        if (node == nullptr) return true;
        if (node->val >= max || node->val <= min) return false;
        return isValidBST(node->left, min, node->val)
               && isValidBST(node->right, node->val, max);
    }
};

int main() {
    Solution sln;
    TreeNode node;
    node.val = INT_MAX;

    std::cout << sln.isValidBST(&node) << std::endl;
    return 0;
}

