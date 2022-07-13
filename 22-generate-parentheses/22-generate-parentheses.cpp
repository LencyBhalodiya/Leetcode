class Solution {
private:
 void solve(int open ,int close ,int n , string temp,vector<string> &ans)
 {
     if(open == n && close == n){
         ans.push_back(temp);
         return;
     }
     if(open < n)    //open bracket should be less than n
     solve(open +1, close , n,temp+"(",ans);    // add open bracket and raise the count
     if(close < open)     //close bracket always should be less than open to be well -formed
     solve(open, close+1 , n,temp + ")",ans);     //increment close bracket ++
    
     //no backtracking required
 }
public:
    vector<string> generateParenthesis(int n) {
        string temp = "";
       vector<string> ans;
        solve(0,0,n, temp, ans);
        return ans;
    }
};