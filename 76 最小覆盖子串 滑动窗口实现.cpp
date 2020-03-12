class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> t_map;
		unordered_map<char, int> win_map;
		for (auto a : t)
			t_map[a]++;
		int left = 0, right = 0, s_size = s.size(), match = 0, minLen = INT_MAX, start = 0;
		while (right < s_size)
		{
			char curr = s[right];
			if (t_map.count(curr))
			{
				win_map[curr]++;
				if (win_map[curr] == t_map[curr])
					match++;
			}
			++right;
			while (match == t_map.size())
			{
				if (minLen > (right - left))
				{
					minLen = right - left;
					start = left;
				}
				curr = s[left];
				if (t_map.count(curr))
				{
					win_map[curr]--;
					if (win_map[curr] < t_map[curr])
						match--;
				}
				++left;
			}
		}
		return minLen == INT_MAX ? "" : s.substr(start, minLen);
	}
}; 
