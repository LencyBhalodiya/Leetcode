class Solution {
private:
void dfs(vector<vector<char>> &grid,int i , int j)
{
    if(i < 0 || j < 0 || i >= grid.size() || j>=grid[0].size() || grid[i][j] == '0')
        return;
    //if element is 1 then turn its horizontal and vertical elemnt to 0 if it is 1;
      grid[i][j] = '0';
      dfs(grid,i+1,j); //downside
      dfs(grid,i-1,j); // upside
       dfs(grid,i,j+1); // right
      dfs(grid,i,j-1); // leftside

}
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row == 0) return 0;
        int island = 0;
        
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    island++;
                }
            }
        }
        return island;
    }
};