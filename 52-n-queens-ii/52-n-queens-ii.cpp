class Solution {
private:
bool isSafe(vector<string> arr,int row,int col,int n)
{
  for(int rows = 0 ; rows < row ; rows++){
      if(arr[rows][col] == 'Q')
      return false;
  } 
  // check diagonal left
  for (int i=row, j=col; i>=0 && j>=0; i--, j--)
      if (arr[i][j] == 'Q') 
         return false;
    
   //check diagnal right
  for (int i=row, j=col; j<n && i>=0; i--, j++)
      if (arr[i][j] == 'Q') 
        return false;

  return true;
}
private:
void nQueen( vector<string> &temp, vector<vector<string>> &arr,int row,int n)
{
    if(row ==  n)
    {
      arr.push_back(temp);
     return;
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        if(isSafe(temp,row,i,n))
        {
            temp[row][i] = 'Q';
            nQueen(temp,arr,row+1,n); // if safe is true then place Queen and move to next row;
            temp[row][i] = '.'; // if erase before backtracking
        }
    }

}

public:
    int totalNQueens(int n) {
         vector<vector<string>> res;
      vector<string> temp(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            temp[i] = s; 
        }
       nQueen(temp,res,0,n);
       int count = 0;
         return res.size();  
    }
};