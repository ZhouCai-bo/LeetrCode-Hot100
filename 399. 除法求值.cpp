class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		vector<double> res;
		map<string, pair<string, double>> pre;
		for (int i = 0; i < values.size(); i++)
		{
			if (!pre.count(equations[i][0]))
				pre[equations[i][0]] = make_pair(equations[i][0], 1);
			if (!pre.count(equations[i][1]))
				pre[equations[i][1]] = make_pair(equations[i][1], 1);
			join(equations[i][0], equations[i][1], values[i], pre);
		}
		for (int i = 0; i < queries.size(); i++)
		{
			string st1 = queries[i][0];
			string st2 = queries[i][1];
			if (!pre.count(st1) || !pre.count(st2))
			{
				res.push_back(-1.0);
				continue;
			}
			string st1_root = find(st1, pre);
			string st2_root = find(st2, pre);
			if (st1_root != st2_root)
				res.push_back(-1.0);
			else
			{
				double d1 = pre[st1].second;
				double d2 = pre[st2].second;
				res.push_back(d2 / d1);
			}
		}
		return res;
	}

	string find(string &a, map<string,pair<string,double>> &pre)
	{
		if (a != pre[a].first)
		{
			string temp = pre[a].first;
			pre[a].first = find(pre[a].first, pre);
			pre[a].second *= pre[temp].second;
		}
		return pre[a].first;
	}
	void join(string &st1, string &st2, double result, map<string, pair<string, double>> &pre)
	{
		string st1_root = find(st1, pre);
		string st2_root = find(st2, pre);
		if (st1_root != st2_root)
		{
			pre[st2_root].first = st1_root;
			pre[st2_root].second = pre[st1].second*result / pre[st2].second;
		}
	}
	
};
