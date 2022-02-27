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
    bool valid(long long minn, long long maxx,TreeNode*root)
    {
        if(root==NULL) return true;
        if(root->val>=maxx || root->val<=minn) return false;
        
        return valid(minn,root->val,root->left) && valid(root->val,maxx,root->right);
    }
    bool isValidBST(TreeNode* root) {
        
        long long minn=0LL+INT_MIN-1;
        long long maxx=0LL+INT_MAX+1;
        
        return valid(minn,maxx,root);
    }
};