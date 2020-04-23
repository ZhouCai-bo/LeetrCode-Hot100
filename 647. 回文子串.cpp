class Solution {
public:
	int countSubstrings(string s) {
		int size = s.size(), cnt = 0;
		vector<vector<bool>> dp(size + 1, vector<bool>(size + 1));
		/*for (int i = 0; i < size; i++)
			dp[i][i] = true;*/
		for (int i = 0; i < size; i++)
		{
			for (int j = i; j >= 0; j--)
			{
				if (i == j) dp[i][j] = true;
				else if (s[i] == s[j] && (j + 1 == i || dp[i - 1][j + 1])) dp[i][j] = true;
				if (dp[i][j]) cnt++;
			}
		}
		return cnt;
	}
};
