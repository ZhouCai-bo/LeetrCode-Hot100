class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		map<char, int> cache;
		vector<char> ts(10000, '#');
		int last = 0;
		for (char &ch : tasks)
		{
			int pos = 0;
			if (!cache.count(ch))
				pos = findpos(ts, 0);
			else if (ts[cache[ch] + n + 1] != '#')
				pos = findpos(ts, cache[ch] + n + 2);
			else
				pos = cache[ch] + n + 1;

			ts[pos] = ch;
			cache[ch] = pos;
			last = max(last, pos);
		}
		return last + 1;
	}

	int findpos(vector<char> &ts, int start)
	{
		for (int i = start; i < ts.size(); i++)
			if (ts[i] == '#')
				return i;
	}
};
