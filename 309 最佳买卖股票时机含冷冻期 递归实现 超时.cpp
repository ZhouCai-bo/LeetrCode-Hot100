class Solution {
public:
	int max = INT_MIN;
	vector<int> prices;

	int maxProfit(vector<int>& prices) {
		this->prices = prices;
		dfs(false, -1, 0, 0);
		return max;
	}
	void dfs(bool buyed, int buyprice, int tolprice, int index){
  		//结束条件
		if (index >= prices.size()){
			if (tolprice > max)
				max = tolprice;
			return;
		}
		//保持
		dfs(buyed, buyprice, tolprice, index + 1);
    		//卖出
		if (buyed){
			if (prices[index] > buyprice){
				tolprice += prices[index] - buyprice;
				dfs(false, buyprice, tolprice, index + 2);
			}	
		}
    		//买入
		else if (!buyed){
			dfs(true, prices[index], tolprice, index + 1);
		}
	}
};
