class Solution {
public:
	unordered_set<string> cache;
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> sset(wordDict.begin(), wordDict.end());
		return findSeq(s, sset);
	}
	bool findSeq(string s, unordered_set<string>& sset)
	{
		if (s.size() == 0)
			return true;
		if (cache.find(s) != cache.end())
			return false;
		for (int i = 1; i <= s.size(); i++)
		{
			string temp = s.substr(0, i);
			if (sset.count(temp) && findSeq(s.substr(i), sset))
				return true;
			else
				cache.insert(s);
		}
		return false;
	}
};
