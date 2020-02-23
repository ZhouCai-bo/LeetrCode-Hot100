class Solution {
public:
	int maxCoins(vector<int>& nums) {
		vector<vector<int>> res(nums.size(), vector<int>(nums.size(), -1));
		int result=recurse(nums, 0, nums.size()-1, res);
		return result;
	}
	int recurse(vector<int>& nums, int left, int right, vector<vector<int>> &res){
		if (left <= right){
			if (res[left][right] != -1)
				return res[left][right];
		}
		if (left == right)
			return (left - 1 >= 0 ? nums[left-1] : 1) * nums[left] * (right + 1 < nums.size() ? nums[right+1] : 1);
		int maxc = 0;
		for (int i = left; i <= right; i++){
			int temp = (left - 1 >= 0 ? nums[left - 1] : 1) * nums[i] * (right + 1 < nums.size() ? nums[right + 1] : 1) 
				+ recurse(nums, left, i - 1, res) + recurse(nums, i + 1, right, res);
			maxc = max(temp, maxc);
		}
		if (right >= left) res[left][right] = maxc;
		return maxc;
	}
};
