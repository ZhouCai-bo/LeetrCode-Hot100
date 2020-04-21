class Solution {
public:
	int res = 0;
	map<pair<int, int>, int> memo;
	int findTargetSumWays(vector<int>& nums, int S) {
		recurse(nums, S, 0);
		return res;
	}

	int recurse(vector<int> &nums, long long curr, int index)
	{
		if (memo.count(make_pair(curr, index)))
		{
			res += memo[make_pair(curr, index)];
			return memo[make_pair(curr, index)];
		}
		if (index >= nums.size())
		{
			if (curr == 0)
			{
				res++;
				return 1;
			}
			return 0;
		}
		int cnt = recurse(nums, curr + nums[index], index + 1) + recurse(nums, curr - nums[index], index + 1);
		memo.insert(make_pair(make_pair(curr, index), cnt));
		return cnt;
	}
};
