class Solution {
private:
bool solve(vector<vector<char>>&board, string &word,int row,int col,int k)
{
     if(k == word.size())
        return true;
    
    //base condition
    if(row < 0 || col < 0 || row >= board.size()|| col >= board[0].size() || board[row][col]!=word[k]) 
        return false ;
    
   
    
    char c= board[row][col];
    board[row][col] = '#';  
                                                                
    bool right = solve(board,word,row,col+1,k+1);
     bool down = solve(board,word,row+1,col,k+1);
    bool up = solve(board,word,row-1,col,k+1);
    bool left = solve(board,word,row,col-1,k+1);
    board[row][col] = c; //backtracking
    
    return( up || down || right || left);
}
public:
    bool exist(vector<vector<char>>& board, string word) {
       int n = board.size(); //size of row
        int m = board[0].size(); // size of col
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j ++){
              if(solve(board,word,i,j,0))
                      return true;
            }
        }
        return false;  
    }
};