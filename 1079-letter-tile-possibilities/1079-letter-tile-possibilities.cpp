class Solution {
private:
  void solve(string arr,int index, int &ans)
  {
      ans++;
      
      for(int i = index; i < arr.size() ; i++)
      {
          if(i > index && arr[i] == arr[index])
              continue;
          
          swap(arr[i],arr[index]);
          solve(arr,index + 1, ans);
          
      }
  }
public:
    int numTilePossibilities(string tiles) {
        int index = 0;
        int ans = -1;
        sort(tiles.begin(),tiles.end());
        solve(tiles,index,ans);
        return ans;
    }
};