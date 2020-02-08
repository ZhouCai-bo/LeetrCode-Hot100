class Solution 
	{
	public:

		int maximalSquare(vector<vector<char>>& matrix) 
		{
			if (matrix.empty() || matrix[0].empty())
				return 0;

			vector<vector<int>> v(matrix.size(), vector<int>(matrix[0].size(), 0));
			int row = matrix.size();
			int cln = matrix[0].size();
			int len = 0;

			//初始化第一行和第一列
			for (int i = 0; i < row; i++)
			{
				if (matrix[i][0] == '1')
					len = max(len, v[i][0] = 1);
					//v[i][0] = 1;
			}
			for (int j = 0; j < cln; j++)
			{
				if (matrix[0][j] == '1')
					len = max(len, v[0][j] = 1);
					//v[0][j] = 1;
			}

			for (int i = 1; i < row; i++)
			{
				for (int j = 1; j < cln; j++)
				{
					if (matrix[i][j] == '1')
					{
						v[i][j] = min(min(v[i - 1][j], v[i - 1][j - 1]), v[i][j - 1]) + 1;
						len = max(len, v[i][j]);
					}
				}

			}
			return len*len;
		}
	};
