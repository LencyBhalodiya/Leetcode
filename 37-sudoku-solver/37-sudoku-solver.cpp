class Solution {
private:
bool solve(vector<vector<char>> &board)
{
    for(int i = 0 ; i < board.size() ; i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            if(board[i][j] == '.') // if board space in empty then fill
            {
                for(char c = '1'; c<= '9' ; c++)
                {
                    if(isSafe(board,i,j,c))
                    {
                        board[i][j] = c; //if isafe is true then fill the element
                        
                        if(solve(board))
                         return true;
                        else
                           board[i][j] = '.'; //if it isn't true then erase the filled element
                    }
                }
                return false;
            }
        }
    }
    return true;
}
private:
bool isSafe(vector<vector<char>> &board, int row, int col, char c)
{
    for(int i = 0 ; i < 9 ; i++) // iterate 9times
    {
      if(board[i][col] == c) //checks for rows
          return false;
        
      if(board[row][i] == c) // checks for the column
          return false;
        
      if(board[3*(row/3)+ i/3][3*(col/3)+i%3] == c) //checks for the particular in 3x3 matrix
          return false;
    }
    return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};