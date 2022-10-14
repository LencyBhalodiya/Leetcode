class Solution {
private:
bool solve(vector<int> &arr , int n)
{
    if(n == 0 || n == 1) return true;
    int maxi = 0;
   for(int i = 0 ; i < n && maxi >= i; i++)
   {
       if(maxi < i + arr[i])
           maxi = i + arr[i];
       if(maxi >= n-1)
           return true;
   }
    return false;
}
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,n);
    }
};