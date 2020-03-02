class Solution {
public:
	vector<string> res;
	vector<string> generateParenthesis(int n) {
		recurse(0,0, n, "");
		return res;
	}
	void recurse(int leftCnt, int rightCnt, int n, string curr)
	{
		if (curr.size() == n * 2)
		{
			res.push_back(curr);
			return;
		}
		if (leftCnt < n)
		{
			recurse(leftCnt + 1, rightCnt, n, curr + "(");
			if (rightCnt < leftCnt)
				recurse(leftCnt, rightCnt + 1, n, curr + ")");
		}
		else if (rightCnt < leftCnt)
			recurse(leftCnt, rightCnt + 1, n, curr + ")");
	}
};
