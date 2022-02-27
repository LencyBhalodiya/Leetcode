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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool reverse = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                
                if(reverse)
                ans[i] = curr->val;
                else
                ans[size-i-1] = curr->val;
                
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            result.push_back(ans);
            ans.clear();
            reverse = !reverse;
        }
        return result;
    }
};