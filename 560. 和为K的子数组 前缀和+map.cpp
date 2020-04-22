class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		map<int, int> memo;
		memo[0] = 1;
		int sum = 0, cnt = 0;
		for (int &a : nums)
		{
			sum += a;
			if (memo.count(sum - k))
				cnt += memo[sum - k];
            memo[sum]++;
		}
		return cnt;
	}
};
