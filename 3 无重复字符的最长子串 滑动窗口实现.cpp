class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0 || s.size() == 1)
			return s.size();
		int max = 1;
		int left = 0, right = 1;
		set<char> had;
		had.insert(s[0]);
		while (right < s.size()){
			if (had.find(s[right]) == had.end()){
				had.insert(s[right]);
				max = max>right - left + 1? max : right - left + 1;
			}
			else{
				while (s[left] != s[right]){
					had.erase(s[left]);
					++left;
				}
				++left;
			}
			++right;
		}
		return max;
	}
};
