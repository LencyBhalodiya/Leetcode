class Solution {
private:
 void solve(string s , int index , vector<string> &res)
 {
     res.push_back(s);
     
      if(index >= s.size())
            return;
     
    for(int j = index ; j < s.length(); j++)
    {
          if (isalpha(s[j])) // check whether char is alphabet or not
            {
              
                s[j]  ^= 32; //convert into upper if lowercase
                solve(s, j+1, res);
                s[j]  ^= 32; //convert into lower if uppercase given
            }
    }
 }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(s,0,res);
        return res;
    }
};