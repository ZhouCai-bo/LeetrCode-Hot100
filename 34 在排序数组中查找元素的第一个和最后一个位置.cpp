class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res = { -1, -1 };
		if (nums.size() < 1) 
			return res;
		int lo = 0, hi = nums.size(), mid;
		while (lo < hi){
			mid = (lo + hi) / 2;
			nums[mid] < target ? lo = mid + 1 : hi = mid;
		}
		if (lo == nums.size()) 
			return res;
		if (target == nums[lo]) 
			res[0] = lo;
		else 
			return res;
		hi = nums.size();
		while (lo < hi){
			mid = (lo + hi) / 2;
			target < nums[mid] ? hi = mid : lo = mid + 1;
		}
		res[1] = lo - 1;
		return res;
	}
};
