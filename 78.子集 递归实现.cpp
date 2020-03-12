class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> subsets(vector<int>& nums) {

		vector<int> temp{};
		add(nums, temp, 0);
		res.push_back(vector<int>{});
		return res;
	}
	void add(vector<int> &nums, vector<int> temp, int index)
	{
		if (index >= nums.size())
			return;
		for (int i = index; i < nums.size(); i++)
		{
			temp.push_back(nums[i]);
			res.push_back(temp);
			add(nums, temp, i + 1);
			temp.pop_back();
		}
	}
}; 
