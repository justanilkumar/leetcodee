class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Boundary check + zero check
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;
        
        int gold = grid[i][j];
        grid[i][j] = 0;  // mark visited
        
        int maxGold = 0;
        
        maxGold = max(maxGold, dfs(grid, i+1, j));
        maxGold = max(maxGold, dfs(grid, i-1, j));
        maxGold = max(maxGold, dfs(grid, i, j+1));
        maxGold = max(maxGold, dfs(grid, i, j-1));
        
        grid[i][j] = gold;  // backtrack
        
        return gold + maxGold;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    result = max(result, dfs(grid, i, j));
                }
            }
        }
        
        return result;
    }
};