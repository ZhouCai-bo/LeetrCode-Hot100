class Solution {
public:
	vector<vector<int>> res;
	int largestRectangleArea(vector<int>& heights) {
		if (heights.size() == 0)
			return 0;
		int max = heights[0], curr = max, size = heights.size(), minL;
		for (int i = 0; i < heights.size();i++){
			minL = heights[i];
			for (int j = i - 1; j >=0; j--){
				if (heights[j]<minL){
					curr = (i - j)*minL;
					max = max>curr ? max : curr;
					minL = heights[j];
				}
			}
			curr = (i + 1)*minL;
			max = max>curr ? max : curr;
		}
		return max;
	}
};
