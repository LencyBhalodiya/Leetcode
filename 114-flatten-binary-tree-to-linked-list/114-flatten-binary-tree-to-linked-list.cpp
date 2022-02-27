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
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        //traverse preoder in reverse order to get the hold of previous node
        flatten(root->right);
        flatten(root->left);
        
        //assign left to NULL and right to prev element
        root->left = NULL;
        root->right = prev;
        
        prev = root;
    }
};