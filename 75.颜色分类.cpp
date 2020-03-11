class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		update(nums, left, right);
		int scan = right;
		while (scan >= left && left<right)
		{
			if (scan>right)
				scan = right;
			if (nums[scan] == 0)
			{
				swap(nums[scan], nums[left]);
				update(nums, left, right);
			}
			else if (nums[scan] == 2)
			{
				swap(nums[scan], nums[right]);
				update(nums, left, right);
			}
			else
				scan--;
		}
	}
	void update(vector<int>& nums, int &left, int &right)
	{
		while (nums[left] == 0 && left + 1 < nums.size()) left++;
		while (nums[right] == 2 && right - 1 >= 0) right--;
	}
}; 
