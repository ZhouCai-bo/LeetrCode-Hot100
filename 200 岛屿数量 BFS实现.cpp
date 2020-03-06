class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {

        int row = grid.size();
        if(!row) return 0;
        int cln = grid[0].size();
        int num_islands = 0;

        queue<pair<int,int>> q;

        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < cln ; j++)
            {
                if(grid[i][j] == '1')
                {
                    ++num_islands;
                    q.push(pair<int,int>(i,j));
                    while(!q.empty())
                    {
                        auto temp = q.front();
                        grid[temp.first][temp.second] = '0';
                        q.pop();

                        if(temp.first - 1 >= 0 && grid[temp.first - 1][temp.second] == '1')
                            q.push(pair<int,int>(temp.first - 1,temp.second));
                        if(temp.first + 1 < row && grid[temp.first + 1][temp.second] == '1')
                            q.push(pair<int,int>(temp.first + 1,temp.second));
                        if(temp.second - 1 >= 0 && grid[temp.first][temp.second - 1] == '1')
                            q.push(pair<int,int>(temp.first,temp.second - 1));
                        if(temp.second + 1 < cln && grid[temp.first][temp.second + 1] == '1')
                            q.push(pair<int,int>(temp.first,temp.second + 1));
                    }
                }
                    
            }
        }

        return num_islands;
    }

    
};
