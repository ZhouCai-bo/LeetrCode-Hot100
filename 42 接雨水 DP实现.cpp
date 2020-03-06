class Solution {
public:
	int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
		vector<int> highest_left(height.size());
		highest_left[0] = 0;
		vector<int> highest_right(height.size());
		highest_right[highest_right.size() - 1] = 0;
		int i = 1;
		for (; i < highest_left.size() - 1; i++)
			highest_left[i] = max(highest_left[i - 1], height[i - 1]);
		for (i = highest_right.size() - 2; i >= 0; i--)
			highest_right[i] = max(highest_right[i + 1], height[i + 1]);
		int rain = 0;
		for (i = 0; i < height.size() - 1; i++)
		{
			int lower = min(highest_left[i], highest_right[i]);
			if (lower > height[i])
				rain += lower - height[i];
		}
		return rain;
	}
};
