/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recursionTree(TreeNode* node, vector<int>& tree) {
        if(node == nullptr)
            return ;
        tree.push_back(node->val);
        recursionTree(node->left, tree);
        recursionTree(node->right, tree);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        recursionTree(root, res);

        return res;
    }
};
