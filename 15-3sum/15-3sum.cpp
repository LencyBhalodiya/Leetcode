class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> res;
        if (nums.size() < 3)
        return res;
        
    sort(nums.begin(),nums.end()); // sort the vector array
    
        
    for(int i=0;i<nums.size()-2;i++)
    {
        if(i==0 || (i>0 && nums[i]!=nums[i-1])) //if the element is not equal to previous
        {
            int lo = i+1;
            int hi = nums.size()-1;
            int sum = 0-nums[i];
            
            while(lo < hi)
            {
                if(sum == nums[lo]+nums[hi])
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    res.push_back(temp);
                
                while(lo<hi && nums[lo]==nums[lo+1]) lo++; //for elimination of repeated element
                while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                
                lo++;
                hi--;
                }
                else if(sum>nums[lo]+nums[hi])
                    lo++;
                else 
                    hi--;
            }
        }
    }
        return res;
    }
};