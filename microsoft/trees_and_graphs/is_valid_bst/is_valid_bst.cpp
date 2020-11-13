#include <iostream>
#include <vector>
#include <stack>
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

    bool isValidBSTRNonRecursive(TreeNode* root) {
        stack<TreeNode*> stack;
        int lastTested;
        bool init = false;
        if (!root) return true;
        stack.push(root);

        while (!stack.empty()) {
            auto node = stack.top();
            stack.pop();

            if (!node->left && !node->right) {
                cout << node->val << " ";
                if (init && lastTested >= node->val) return false;
                init = true;
                lastTested = node->val;
                continue;
            }

            if (node->right) {
                stack.push(node->right);
            }

            (*node).right = nullptr;
            stack.push(node);

            if (node->left) {
                stack.push(node->left);
            }

            (*node).left = nullptr;
        }

        return true;
    }
};

int main() {
    Solution sln;
    TreeNode node;
    node.val = INT_MAX;

    std::cout << sln.isValidBST(&node) << std::endl;
    return 0;
}

