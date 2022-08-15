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
    void traversal(TreeNode* root,priority_queue<int,vector<int>,greater<int>> &p)
    {
        if(root == NULL) return;
        if(root!=NULL)
        p.push(root->val);
        
        traversal(root->left,p);
        traversal(root->right,p);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        traversal(root,pq);
        int ans = 0;
        while(k--)
        {
          ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};