class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
		int left = 0, right = 0, index = 1, wmin = nums[0], wmax = nums[0];
		vector<int> maxs(nums.size());
		vector<int> mins(nums.size());
		maxs[0] = nums[0];
		mins[nums.size() - 1] = nums[nums.size() - 1];

		for (int i = 1; i < nums.size(); i++)
			maxs[i] = max(maxs[i - 1], nums[i]);

		for (int i = nums.size() - 2; i >= 0; i--)
			mins[i] = min(mins[i + 1], nums[i]);

		while (index < nums.size())
		{
			if (nums[index - 1] > nums[index] || nums[index] < wmax)
			{
				right = index;
				wmax = max(wmax, maxs[index]);
			}
			index++;
		}

		wmin = mins[left];
		while (left <= right)
		{
			if (nums[left] == wmin)
			{
				left++;
				wmin = mins[left];
			}
			else if (nums[left] <= nums[left + 1] && nums[left] <= wmin)
			{
				left++;
			}
			else
				break;
		}
		return right - left + 1;
	}
};
