class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int start = bigFlow(nums);
		sort(nums.begin() + start, nums.end());
	}
	int bigFlow(vector<int> &nums){
		int slice = nums.size() - 2;
		while (slice>=0 && nums[slice]>=nums[slice + 1]) slice--;
		if (slice < 0)
			return 0;
		int mid = nums[slice];
		int point = INT_MAX, index;
		for (int i = nums.size() - 1; i > slice; i--){
			if (nums[i] > mid && nums[i] < point){
				point = nums[i];
				index = i;
			}	
		}
		swap(nums[slice], nums[index]);
		return slice + 1;
	}
};
