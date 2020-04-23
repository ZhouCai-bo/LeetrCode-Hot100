class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		map<char, int> cache;
		int maxt = 0, res = 0;
		for (char &ch : tasks)
		{
			cache[ch]++;
			maxt = max(maxt, cache[ch]);
		}
		res += (maxt - 1)*(n + 1);
		for (auto &ele : cache)
			if (ele.second == maxt)
				res++;
		return res > tasks.size() ? res : tasks.size();
	}
};
