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
 int index = 0;
 public: 
   TreeNode *solve(vector<int> &preorder,vector<int> &inorder,int start, int end)
   {
       if(start > end ) return NULL;
       
       int element = preorder[index];
       TreeNode * root = new TreeNode(preorder[index++]); //create node and increment preorder index
       
       int pos ;
       for(int i = start; i < preorder.size() ; i++ )
       {
           if(inorder[i] == element)
           {
               pos = i; // find postion in inorder of element
               break;
           }
       }
       root->left = solve(preorder,inorder,start,pos-1);
      root->right = solve(preorder,inorder,pos+1,end);
       return root;
   }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder ) {
        int index = 0;
      return solve(preorder,inorder,0,preorder.size()-1);
        
    }
};