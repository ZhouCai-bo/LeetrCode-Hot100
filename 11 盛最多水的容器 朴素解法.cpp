class Solution {
public:
	int maxArea(vector<int>& height) {
		int max = 0;
		int left = 0, right = height.size() - 1;
		for (int i = 0; i < height.size() - 1; i++){
			if (height[i] < height[left])
				continue;
			left = i;
			right = height.size() - 1;
			for (int j = height.size() - 1; j >i; j--){
				if (height[j] < height[right])
					continue;
				right = j;
				int cur = (j - i)*((height[i]<height[j]) ? height[i] : height[j]);
				max = (max>cur) ? max : cur;
			}
		}
		return max;
	}
};
