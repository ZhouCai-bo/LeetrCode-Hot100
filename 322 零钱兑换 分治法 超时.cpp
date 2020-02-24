class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==0)
            return -1;
        if(amount==0)
            return 0;
		vector<int> cache( amount + 1, -1);
		for (auto a : coins){
			if (a<=amount)
				cache[a] = 1;
		}
		recurse(cache, amount);
		return cache[amount];
	}
	int recurse(vector<int> &cache, int cur_amount){
		if (cache[cur_amount] != -1)
			return cache[cur_amount];
		if (cur_amount <= 1)
			return -1;
		int minc = INT_MAX;
		for (int i = cur_amount - 1; i > 0; i--){
			int first = recurse(cache, i);
			int second = recurse(cache, cur_amount - i);
			if (first == -1 || second == -1)
				continue;
			int res = first + second;
			 minc = (minc < res ? minc : res);
		}
		cache[cur_amount] = minc = (minc == INT_MAX ? -1 : minc);
        return minc;
	}
};
