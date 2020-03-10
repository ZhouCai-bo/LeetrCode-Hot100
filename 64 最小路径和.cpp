class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		for (int i = 0; i < grid.size(); i++){
			for (int j = 0; j < grid[0].size(); j++){
				if ((i - 1 < 0) && (j - 1 < 0))
					continue;
				else{
					int a = (i - 1 >= 0) ? grid[i - 1][j] : INT_MAX;
					int b = (j - 1 >= 0) ? grid[i][j - 1] : INT_MAX;
					grid[i][j] += min(a, b);
				}
			}
		}
		return grid[grid.size() - 1][grid[0].size() - 1];
	}
}; 
