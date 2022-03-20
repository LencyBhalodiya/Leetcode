class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
       vector<int> ans;
        unordered_map<int,int>mp;
        //store count of variable in map
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        
        priority_queue<pair<int,int>>pq;//create max heap priority queue
        //push element to max heap acc. to highest count of array elements
        for(auto it:mp)
            pq.push({it.second,it.first});   
        //traverse queue till k since top has highest k element
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);    
            pq.pop();
        }
        return ans;

    }
};