class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<vector<string>> dp(n + 1);
		dp[0].push_back("");
		dp[1].push_back("()");
		for (int i = 2; i <= n; i++){
			for (int j = 0; j < i; j++){
				for (auto a : dp[j]){
					for (auto b : dp[i - 1 - j])
						dp[i].push_back("(" + a + ")" + b);
				}
			}
		}
		return dp[n];
	}
};
