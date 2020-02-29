class Solution {
public:
	int maxArea(vector<int>& height) {
		int max = 0;
		int left = 0, right = height.size() - 1, mL = 0, mR = height.size() - 1;
		while (left < right)
		{
			if (height[left] < height[mL]){ left++; continue; }
			mL = left;
			if (height[right] < height[mR]){ right--; continue; }
			mR = right;
			int minEdge = (height[left] < height[right]) ? left : right;
			int cur = (right - left)*height[minEdge];
			max = (max>cur) ? max : cur;
			if (minEdge == left)
				left++;
			else
				right--;
		}
		return max;
	}
};
