// 思路: 【回溯】后序遍历 左右中

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root == NULL) || (root == p) || (root == q)) {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if((left != NULL) && (right != NULL)) {
            return root;
        }else if((left == NULL) && (right == NULL)) {
            return NULL;
        }else if((left == NULL) && (right != NULL)) {
            return right;
        }else if((left != NULL) && (right == NULL)) {
            return left;
        }
        return NULL;
    }
};
