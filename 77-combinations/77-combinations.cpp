class Solution {
private:
void solve(int n , int k , vector<int> &temp, vector<vector<int>> &ans,int i)
{
    if(temp.size() == k)
    {
        ans.push_back(temp);
        return;
    }
    for(int j = i ; j<= n ; j++)
    {
        temp.push_back(j); //push to temporary array;
        solve(n,k,temp,ans,j+1); //move one step
        temp.pop_back(); //backtrack
    }
}
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(n,k , temp, res,1);
        return res;
    }
};