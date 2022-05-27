class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       unordered_map<int,int> mp;
        vector<int> res;
        for(int i = 0 ; i < nums.size(); i++)
            mp[nums[i]]++;
        
        vector<int>ans;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            int element =it->first;
            int occur= it->second;
             if(occur>nums.size()/3){
             ans.push_back(element);
             }
        }
        return ans;
       
    }
};