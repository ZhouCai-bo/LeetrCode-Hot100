class Solution {
public:
	string s;
	set<string> res;
	int maxdel = INT_MAX;

	vector<string> removeInvalidParentheses(string s) {
		this->s = s;
		dfs("", 0, 0, 0, 0);
		vector<string> resv(res.begin(), res.end());
		return resv;
	}

	void dfs(string temp, int index, int leftcnt, int rightcnt, int delcnt)
	{
		if (index >= s.size())
		{
			if (leftcnt != rightcnt)
				return;
			if (delcnt == maxdel)
				res.insert(temp);
			else if (delcnt < maxdel)
			{
				res.clear();
				res.insert(temp);
				maxdel = delcnt;
			}
			return;
		}
		dfs(temp, index + 1, leftcnt, rightcnt, delcnt + 1);
		//回溯
		if (s[index] == '(')
			dfs(temp + '(', index + 1, leftcnt + 1, rightcnt, delcnt);
		else if (s[index] == ')')
		{
			//没有足够的左括号和再出现的右括号匹配
			if (rightcnt + 1 > leftcnt) return;
			dfs(temp + ')', index + 1, leftcnt, rightcnt + 1, delcnt);
		}
		else
			dfs(temp + s[index], index + 1, leftcnt, rightcnt, delcnt);
	}
};
