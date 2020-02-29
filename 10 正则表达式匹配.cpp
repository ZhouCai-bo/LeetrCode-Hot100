class Solution {
public:
	bool isMatch(string s, string p) {
		int size_s = s.size(), size_p = p.size();
		vector<vector<bool>> dp(size_s + 1, vector<bool>(size_p + 1));
		dp[0][0] = 1;
		for (int i = 0; i < size_p; i++){
			if (p[i] == '*' && dp[0][i - 1])
				dp[0][i + 1] = 1;
		}
		for (int i = 0; i < size_s; i++){
			for (int j = 0; j < size_p; j++){
				if (s[i] == p[j] || p[j] == '.')
					dp[i + 1][j + 1] = dp[i][j];
				else if (p[j] == '*'){
					if (p[j - 1] != s[i] && p[j - 1] != '.')
						dp[i + 1][j + 1] = dp[i + 1][j - 1];
					else
						dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1]);
				}
			}
		}
		return dp[size_s][size_p];
	}
};
