class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowp=nums[0];
        int fastp=nums[0];
        //find loop in array and stick slow pointer their
        do{
              slowp=nums[slowp];
              fastp=nums[nums[fastp]];
        }while(slowp!=fastp);
            
        fastp=nums[0]; //make fast pointer at start
        //move both one step till it matches
        while(slowp!=fastp)
        {
            slowp=nums[slowp];
            fastp=nums[fastp];
        }
        return slowp;
    }
};