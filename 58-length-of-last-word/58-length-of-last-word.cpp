class Solution {
public:
    int lengthOfLastWord(string s) {
        bool flag  = false;
        int count = 0;
        
        for(int i = s.length()-1; i>=0 ; i--)
        {
           if(s[i] == ' ' && flag )
                break;
           else{
                if(s[i]!= ' ')
                {
                    count++;
                    flag = true;
                }
            }
        }
        return count;
    }
};