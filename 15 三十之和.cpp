class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> v;
		if (nums.size()<3)
			return v;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++){
			if (nums[i]>0)
				continue;
			if (i>0 && nums[i] == nums[i - 1])
				continue;
			int left = i + 1;
			int right = nums.size() - 1;
			while (left <right){
				if (nums[i] + nums[left] + nums[right] == 0) {
					while (left + 1<right && nums[left] == nums[left + 1])++left; //排除左重复
					while (left<right - 1 && nums[right] == nums[right - 1])--right; //排除右重复
					v.push_back(vector<int>{nums[i], nums[left], nums[right]});
					++left;
					--right;
				}
				else if (nums[i] + nums[left] + nums[right] > 0)
					right--;
				else 
					left++;
			}	
		}
		return v;
	}
};
