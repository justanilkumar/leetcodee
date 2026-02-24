class Solution {
public:
    vector<vector<string>> result;
    
    void solve(int row, int n, vector<string>& board, 
               vector<int>& col, vector<int>& diag, vector<int>& antiDiag) {
        
        if(row == n) {
            result.push_back(board);
            return;
        }
        
        for(int c = 0; c < n; c++) {
            
            if(col[c] || diag[row - c + n - 1] || antiDiag[row + c])
                continue;
            
            // place queen
            board[row][c] = 'Q';
            col[c] = diag[row - c + n - 1] = antiDiag[row + c] = 1;
            
            solve(row + 1, n, board, col, diag, antiDiag);
            
            // backtrack
            board[row][c] = '.';
            col[c] = diag[row - c + n - 1] = antiDiag[row + c] = 0;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        vector<int> col(n, 0);
        vector<int> diag(2*n - 1, 0);
        vector<int> antiDiag(2*n - 1, 0);
        
        solve(0, n, board, col, diag, antiDiag);
        
        return result;
    }
};