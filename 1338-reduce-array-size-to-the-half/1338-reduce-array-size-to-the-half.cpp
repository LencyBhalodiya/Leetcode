class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> maxheap;
        int count = 0 ;
        //store value with frequency in map
        for(int i = 0 ; i < n ; i++)
            mp[arr[i]]++;
        
        for(auto it : mp) //store max frequency according 
           maxheap.push({it.second,it.first});
        
        int ans = 0;
        while(!maxheap.empty())
        {
            ans += maxheap.top().first;
            maxheap.pop();
            count++;
            if(ans >= n/2)
                break;
        }
     return count;
    }
};