class Solution {
public:
    void dfs(vector<vector<char>>& grid , int i , int j)
    {
        
        int row = grid.size();
        int cln = grid[0].size();
        grid[i][j] = '0';

        if(i - 1 >= 0 && grid[i - 1][j] == '1')
            dfs(grid , i - 1 , j);
        if(i + 1 < row && grid[i + 1][j] == '1')
            dfs(grid , i + 1 , j);
        if(j - 1 >= 0 && grid[i][j - 1] == '1')
            dfs(grid , i , j - 1);
        if(j + 1 < cln && grid[i][j + 1] == '1')
            dfs(grid , i , j + 1);
        

    }

    int numIslands(vector<vector<char>>& grid) {

        
        int row = grid.size();
        if(!row) return 0;
        int cln = grid[0].size();
        int num_islands = 0;

        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < cln ; j++)
            {
                if(grid[i][j] == '1')
                {
                    ++num_islands;
                    dfs(grid , i , j);
                }
                    
            }
        }

        return num_islands;
    }

    
};
