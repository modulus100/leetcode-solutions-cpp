
#include <iostream>
#include <vector>
#include "../../../shared/tree_node.cpp"

using namespace std;

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
    cout << "test" << endl;
    return 0;
}