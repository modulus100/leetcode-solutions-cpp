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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        recursiveTraversal(root, &vec);
        return vec;
    }

    void recursiveTraversal(TreeNode* node, vector<int>* vec) {
        if (node == nullptr) return;
        vec->push_back(node->val);
        recursiveTraversal(node->left, vec);
        recursiveTraversal(node->right, vec);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
