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
private:
 void solve(TreeNode* root, vector<string> &ans, string temp)
 {
     if(root->left == NULL && root->right == NULL)
     {
         ans.push_back(temp);
         return;
     }
      if(root->left)
         solve(root->left, ans , temp + "->" + to_string(root->left->val));
      if(root->right)
          solve(root->right,ans , temp + "->" + to_string(root->right->val));

 }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        solve(root,ans, temp + to_string(root->val));
        return ans;
    }
};