class Solution {
private:
     bool checkCommon(bitset<26> &a, bitset<26> &b){ // function to check if two bitset are common
        for(int i=0;i<26;i++) if(a[i] && b[i]) return true; // if any of the bits are true, return true
        return false; // otherwise return false
    }
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int res = 0;
        vector<bitset<26>> chars(n); //define array of biset of size 26
        
        for(int i = 0 ; i < n ; i++)
        {
            for(auto &ch: words[i]){
                chars[i][ch-'a'] = 1; //insert 1 if letters is present
            }
            
            for(int j = 0 ; j < i ; j++ )
            {
                if(!checkCommon(chars[i],chars[j])) //match the letter
                     res = max(res, (int)words[i].size()*(int)words[j].size()); // update the answer
            }
        }
        return res;
    }
};