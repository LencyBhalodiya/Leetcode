class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j;
        int n = nums.size();
        
        for( i = n-2 ; i >= 0 ; i-- )
        {
            if(nums[i] < nums[i+1]) //find first less element than its next element from last of index
                break;
        }
        if(i < 0){
         reverse(nums.begin(),nums.end());
        }
        else{
            for(j = n-1 ; j > i ; j--) //start from last and find element bigger than ith element
            {
                if(nums[j] > nums[i])
                    break;
            }
            cout<<i<<j;
        swap(nums[i],nums[j]); //swap the element
        reverse(nums.begin()+i+1,nums.end()); //reverse it
        }
    }
};