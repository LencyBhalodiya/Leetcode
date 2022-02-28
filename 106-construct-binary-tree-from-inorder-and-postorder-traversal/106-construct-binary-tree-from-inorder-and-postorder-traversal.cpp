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
     TreeNode* helper(vector<int>& in, vector<int>& post, int low, int high, int& index)
    {
        if(low > high)
            return NULL;
        
        TreeNode* root = new TreeNode(post[index--]);
        int pos = 0;
        for(int i = low; i <= high; i++)
        {
            if(in[i] == root->val)
            {
                pos = i;
                break;
            }
        }
        root -> right = helper(in, post, pos + 1, high, index);
        root -> left = helper(in, post, low, pos - 1, index);
        return root;
    }
   
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size()-1;
        int end = postorder.size()-1;
        return helper(inorder,postorder,0,end,index);
    }
};