#include <iostream>
#include <vector>
#include "../../../shared/tree_node.cpp"

using namespace std;

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
