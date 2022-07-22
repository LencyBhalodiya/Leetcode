class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> matrix(n, vector<int>(n, 0)); //create n row of vector<int>
        
        int startingRow = 0;
        int endingRow = n - 1;
        int startingCol = 0;
        int endingCol = n - 1;
        int dir = 0; 
        int num = 1;
        
        while(startingRow <= endingRow && startingCol <= endingCol) {
            if(dir == 0) {
                //print starting row
                for(int c = startingCol; c <= endingCol; c++) {
                    matrix[startingRow][c] = num++;
                }
                dir++;
                startingRow++;
            } else if (dir == 1) {
                //print ending Col
                for(int r = startingRow; r <= endingRow; r++) {
                    matrix[r][endingCol] = num++;
                }
                dir++;
                endingCol--;
            } else if (dir == 2) {
                //print ending Row
                for(int c = endingCol; c >= startingCol; c--) {
                    matrix[endingRow][c] = num++;
                }
                dir++;
                endingRow--;
            } else if (dir == 3) {
                //print first col
                for(int r = endingRow; r >= startingRow; r--){
                    matrix[r][startingCol] = num++;
                }
                dir = 0;
                startingCol++;
            }
        }      
        return matrix;
    }
};