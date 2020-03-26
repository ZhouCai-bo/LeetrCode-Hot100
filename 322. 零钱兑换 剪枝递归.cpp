class Solution {
public:
	int min_coins = INT_MAX;
	int coinChange(vector<int>& coins, int amount) {
		unordered_map<int, int> cache;
		return recurse(coins, amount, cache);
	}
	int recurse(vector<int>& coins, int amount, unordered_map<int,int> &cache)
	{
		if (amount == 0)
			return 0;
		if (amount < 0)
			return -1;
		if (cache.find(amount) != cache.end())
			return cache[amount];
		int minc = INT_MAX;
		for (int i = 0; i < coins.size(); i++)
		{
			int temp = recurse(coins, amount - coins[i], cache);
			if (temp != -1)
				minc = min(minc, 1 + temp);
		}
		minc = minc == INT_MAX ? -1 : minc;
		cache[amount] = minc;
		return minc;
	}
};
