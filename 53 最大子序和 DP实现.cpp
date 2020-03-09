class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max = INT_MIN, curr = 0;
		for (auto a : nums){
			curr = (curr + a) > a ? curr + a : a;
			max = max > curr ? max : curr;
		}
		return max;
	}
};
