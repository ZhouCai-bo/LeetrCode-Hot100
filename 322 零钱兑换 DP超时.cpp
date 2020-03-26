class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount+1, -1);
        set<int> coins_set(coins.begin(),coins.end());
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            if(coins_set.count(i))
                dp[i]=1;
            else
            {
                int min_coins=INT_MAX;
                for(int j=1; j <= i/2; j++)
                {
                    if(dp[j]!=-1 && dp[i-j]!=-1)
                        min_coins=min(min_coins, dp[j]+dp[i-j]);
                }
                dp[i]=min_coins==INT_MAX?-1:min_coins;
            }

        }
		return dp[amount];
	}
};
