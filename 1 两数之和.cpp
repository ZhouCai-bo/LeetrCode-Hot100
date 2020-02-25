class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			int temp = target - nums[i];
			if (m.find(temp) != m.end())
				return vector<int>{i,m[temp]};
			m.insert(make_pair(nums[i], i));
		}
		return vector<int>{};
	}
};
