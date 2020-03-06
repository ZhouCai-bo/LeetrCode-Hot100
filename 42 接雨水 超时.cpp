class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = height.size() - 1, rain = 0;
		while (1)
		{
			//确认左右区间
			while (left < right && height[left] == 0)
				left++;
			while (left < right && height[right] == 0)
				right--;
			if (left>=right)
				break;
			for (int i = left; i <= right; i++)
			{
				if (height[i] == 0)
					rain += 1;
				else
					height[i]--;
			}
		}
		return rain;
	}
};
