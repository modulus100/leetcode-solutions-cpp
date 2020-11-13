#include <deque>
#include <queue>
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
            auto node = nodeQueue.front();
            auto level = levelQueue.front();
            nodeQueue.pop_front();
            levelQueue.pop_front();

            if (result.size() < level) {
                vector<int> levelNodes;
                levelNodes.push_back(node->val);
                result.push_back(levelNodes);
            } else {
                auto levelNodes = result[level - 1];
                levelNodes.push_back(node->val);
                result.pop_back();
                result.push_back(levelNodes);
            }

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

    vector<vector<int>> levelOrderBest(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> nodesQueue;
        vector<int> levelValues;
        int n;

        nodesQueue.push(root);

        while(!nodesQueue.empty())
        {
            n = nodesQueue.size();

            while(n--)
            {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                levelValues.push_back(node->val);

                if (node->left)
                    nodesQueue.push(node->left);

                if (node->right)
                    nodesQueue.push(node->right);
            }

            result.push_back(levelValues);
            levelValues.clear();
        }

        return result;
    }
};


int main() {
    Solution sln;
    TreeNode node1;
    TreeNode node2;
    TreeNode node3;

    TreeNode node4;
    TreeNode node5;
    TreeNode node6;
    TreeNode node7;

    node1.val = 3;
    node2.val = 9;
    node3.val = 20;

    node4.val = 1;
    node5.val = 6;
    node6.val = 7;
    node7.val = 2;

    node1.left = &node2;
    node1.right = &node3;

    node1.left->left = &node4;
    node1.left->right = &node5;
    node1.right->left = &node6;
    node1.right->right = &node7;

    auto result = sln.levelOrderBest(&node1);

    return 0;
}

