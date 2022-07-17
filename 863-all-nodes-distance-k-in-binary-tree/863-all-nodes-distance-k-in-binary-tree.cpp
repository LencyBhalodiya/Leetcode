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
private:
 void solve(TreeNode *root , unordered_map<TreeNode*,TreeNode*> &mp)
 {
     TreeNode *curr = root;
     queue<TreeNode*> q;
     q.push(root);
     
     while(!q.empty())
     {
         TreeNode *element = q.front();
         q.pop();
         if(element->left){
             mp[element->left] = element; //track parent node
             q.push(element->left);
         }
         if(element->right){
             mp[element->right] = element; //track parent node
             q.push(element->right);
         }
     }
 }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      unordered_map<TreeNode*,TreeNode*> mp;
        solve(root,mp); //allocate parent node by using hash
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            if(curr_level++ == k ) break; //stop when k level in pushed into queue
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left!=NULL && !visited[curr->left]){ //push to queue of isn't NULL or visted already
                     q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right!=NULL && !visited[curr->right]){
                     q.push(curr->right);
                    visited[curr->right] = true;
                }
                 if(mp[curr] && !visited[mp[curr]]) { //also push parent node
                    q.push(mp[curr]);
                     cout<<q.front()->val;
                    visited[mp[curr]] = true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};