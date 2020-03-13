class Solution {
public:
	vector<vector<int>> res;
	int largestRectangleArea(vector<int>& heights) {
		stack<int> st;
		st.push(-1);
		int maxArea = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			while (st.top() != -1 && heights[i] < heights[st.top()])
			{
				int top = st.top();
				st.pop();
				maxArea = max(heights[top] * (i - st.top() - 1), maxArea);
			}
			st.push(i);
		}
		while (st.top() != -1)
		{
			int top = st.top(), temp = heights[top] * (heights.size() - st.top() - 1);
			st.pop();
			maxArea = max(temp, maxArea);
		}
		return maxArea;
	}
}; 
