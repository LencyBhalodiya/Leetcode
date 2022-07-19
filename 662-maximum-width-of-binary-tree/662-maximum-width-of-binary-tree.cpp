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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans = 0;
        
        while(!q.empty())
        {
          int size = q.size();
          int minn = q.front().second; // store num value
           int first ,last;
          for(int i = 0 ; i < size; i++)
          {
              //curr_num state that which node is being proceed minn is the first node assigned value
            int curr_num = q.front().second-minn; 
             TreeNode *curr = q.front().first;
              q.pop();
              if(i == 0)
                first = curr_num; //store curr_num value of first and last node to calculate total width
              if(i == size-1)
                last = curr_num;
              
              if(curr->left)
                 q.push({curr->left,curr_num*2LL+1});
              if(curr->right)
                  q.push({curr->right,curr_num*2LL+2});
          }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};