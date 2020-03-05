class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> m;
		for (int i = 0; i<nums.size(); i++)
		{
			if (m.find(nums[i]) == m.end())
			{
				m.insert(pair<int, int>(nums[i], 1));
			}
			else
			{
				m.find(nums[i])->second++;
			}
		}
		map<int, int>::iterator iter = m.begin();
		for (; iter != m.end(); iter++)
		{
			cout << iter->first << "xxx" << iter->second << endl;
			if (iter->second > nums.size() / 2)
			{
				return iter->first;
			}
		}
		return 0;
	}
};
