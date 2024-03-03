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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> tree;
        tree.push(root);
        
        while(!tree.empty()) {
            int size = tree.size();
            vector<int> level;

            // 一定要用固定值size, 因为tree的size在动态变化
            for(int i = 0; i < size; i++) {               
                TreeNode* top = tree.front();
                tree.pop();
                level.push_back(top->val);
                
                if(top->left) {
                    tree.push(top->left);
                }
                if(top->right) {
                    tree.push(top->right);
                }
            }
            res.push_back(level);
        }

        return res;
    }
};
