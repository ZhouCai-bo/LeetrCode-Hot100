class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
			return 0;
		int left = 0, right = 1, max_val = 0;
		while (right < prices.size())
		{
			if (prices[left] > prices[right])
			{
				left = right;
				++right;
				continue;
			}
			max_val = max(max_val, prices[left] - prices[right]);
			right++;

		}
		return max_val;
	}
};
