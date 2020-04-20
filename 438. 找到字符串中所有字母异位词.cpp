class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		map<char, int> memo, check;
		vector<int> res;
		for (auto &a : p)
			memo[a]++;
		int start = 0, end = 0, cnt = 0;
		while (end < s.size())
		{
			char curr = s[end];
			if (memo.count(curr))
			{
                check[curr]++;
				cnt++;
				if (memo[curr] < check[curr])
				{
					int temp = s.find_first_of(curr, start);
					cnt -= temp - start + 1;
					for (; start <= temp; start++)
						check[s[start]]--;
				}
				else if(cnt == p.size())
				{
					res.push_back(start);
					cnt--;
					check[s[start]]--;
					start++;
				}
			}
			else
			{
				check.clear();
				cnt = 0;
				start = end + 1;
			}
            end++;
		}
		return res;
	}
};
