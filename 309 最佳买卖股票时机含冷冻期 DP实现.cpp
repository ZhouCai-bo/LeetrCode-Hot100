class Solution {
public:
	int maxProfit(vector<int>& prices) {
        if(prices.size()==0 || prices.size()==1) return 0;
		vector<int> hold(prices.size());
		vector<int> unhold(prices.size());
		hold[0] = -prices[0];
		hold[1] = max(hold[0], -prices[1]);
		unhold[0] = 0;
		unhold[1] = max(unhold[0], hold[0] + prices[1]);
        	int maxVal=max(hold[1],unhold[1]);
		for (int i = 2; i < prices.size(); i++){
			hold[i] = max(hold[i - 1], unhold[i - 2] - prices[i]);
			unhold[i] = max(unhold[i - 1], hold[i - 1] + prices[i]);
			maxVal = max(max(hold[i], unhold[i]), maxVal);
		}
		return maxVal;
	}

};
