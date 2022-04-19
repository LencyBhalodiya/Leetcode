class Solution {
public:
    bool isPalindrome(string s) {
       string ans;
        int n = s.length();
        int left = 0;
        if(n <=1) return true;
        int k = 0;
        for(int i = 0 ; i < n ; i++)
        {
          if( s[i]>= 'a' && s[i]<='z' ){
           ans.push_back(s[i]);
          }
            else if( s[i]>='A' && s[i]<='Z'){
                char a = (s[i] - 'A')+97;
                   ans.push_back(a);
            }else if( s[i]>= '0' && s[i]<='9')
                           ans.push_back(s[i]);
        }
        for(int i = 0 ; i < ans.length(); i++)
            cout<<ans[i];
        int right = ans.length()-1;
        while(left<=right){
            if(ans[left] != ans[right])
                return false;
           left++;
            right--;
            
        }
        return true;
    }
};