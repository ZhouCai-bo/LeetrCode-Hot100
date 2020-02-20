class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		valarray<int> res(1, nums.size());
		res[0] = 1;
		int max = 1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			for (int j = i + 1; j < nums.size(); j++){
				if (nums[i] < nums[j] && res[i] < 1 + res[j]){
					res[i] = 1 + res[j];
					if (max < res[i]) max = res[i];
				}
			}
		}
		return max;
	}
};
