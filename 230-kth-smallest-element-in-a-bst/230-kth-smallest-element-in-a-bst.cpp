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
    int ans = 0;
private:
    void traversal(TreeNode* root,int &k)
    {
        if(root == NULL) return;
        traversal(root->left,k);
        if(--k == 0){ // inorder gives us increasing number traversal
            ans = root->val;
            return;
        }
        traversal(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        traversal(root,k);
      
        return ans;
    }
};