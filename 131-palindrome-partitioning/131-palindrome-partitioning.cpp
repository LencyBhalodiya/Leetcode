class Solution {
private:
bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
private:
void solve(string &s,vector<vector<string>> &ans,vector<string> &path,int index)
{
    if(index == s.size()){
        ans.push_back(path);
        return;
    }
    for(int j = index ; j < s.length() ; j++)
    {
        if(isPalindrome(s,index,j))
        {                               //check for palindrome
         path.push_back(s.substr(index, j - index + 1)); // str(starting pos, no of element from start)
          solve(s,ans,path,j+1);
            path.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(s,ans,path,0);
        return ans;
    }
};