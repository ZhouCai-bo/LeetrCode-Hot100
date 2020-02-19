class Solution {
	public:
		int findDuplicate(vector<int>& nums)
		{
			int slow = nums[0], fast = nums[nums[0]];
			while (slow != fast)
			{
				slow = nums[slow];
				fast = nums[nums[fast]];
			}
			//第一次相遇
			fast = 0;
			while (slow != fast)
			{
				slow = nums[slow];
				fast = nums[fast];
			}
			//第二次相遇
			return fast;
		}
	};
