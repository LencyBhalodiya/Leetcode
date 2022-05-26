class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int n  = cards.size();
        int res = n+1;
        
        for(int i = 0 ; i< n ; i++)
        {
          if(mp.find(cards[i]) != mp.end())
             res= min(res, i - mp[cards[i]] + 1); 
            
            mp[cards[i]] = i;
     }
        
        return res == n+1? -1 :res;
    }
};