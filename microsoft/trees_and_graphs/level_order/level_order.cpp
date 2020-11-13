#include <deque>
#include <vector>
#include "../../../shared/tree_node.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        deque<int> levelQueue;
        deque<TreeNode*> nodeQueue;

        if (root == nullptr) return result;
        nodeQueue.push_back(root);
        levelQueue.push_back(1);

        while(!nodeQueue.empty()) {
            vector<int> levelNodes;
            auto node = nodeQueue.front();
            auto level = levelQueue.front();
            nodeQueue.pop_front();
            levelQueue.pop_front();

            if (result.size() < level) {
                result.push_back(levelNodes);
            } else {
                levelNodes = result[level - 1];
            }

            levelNodes.push_back(node->val);

            if (node->left != nullptr) {
                nodeQueue.push_back(node->left);
                levelQueue.push_back(level + 1);
            }

            if (node->right != nullptr) {
                nodeQueue.push_back(node->right);
                levelQueue.push_back(level + 1);
            }
        }

        return result;
    }
};


int main() {
    Solution sln;
    TreeNode node1;
    TreeNode node2;
    TreeNode node3;

    node1.val = 3;
    node2.val = 9;
    node3.val = 20;

    node1.left = &node2;
    node1.right = &node3;

    auto result = sln.levelOrder(&node1);

    return 0;
}

