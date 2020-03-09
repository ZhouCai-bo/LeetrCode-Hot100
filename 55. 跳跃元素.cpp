class Solution {
public:
	bool canJump(vector<int>& nums) {
		set<int> stop;
		return preStep(nums, nums.size() - 1, stop);
	}
	bool preStep(vector<int> &nums, int now, set<int> &stop)
	{
		if (now == 0)
			return true;
		for (int i = now - 1; i >= 0; i--)
		{
			if (stop.find(i)==stop.end() && nums[i] + i >= now && preStep(nums, i, stop))
				return true;
			else
				stop.insert(i);
		}
		return false;
	}
};
