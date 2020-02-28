class Solution {
public:
	string longestPalindrome(string s) {
		int left = 0, right = 0;
		int max = 1, mL = 0, mR = 0;
		while (right<s.size()){
			int cur = 1;
			//相同字符加入子串，且不用再次确定长度
			while ((right + 1) < s.size() && s[right] == s[right + 1]){
				cur++;
				right++;
			}
			int L = left, R = right;
			while ((L - 1 >= 0 && R + 1 < s.size()) && s[L - 1] == s[R + 1]){
				L--;
				R++;
				cur += 2;
			}
			if (max < cur){
				max = cur;
				mL = L;
				mR = R;
			}
			right++;
			left = right;
		}
		return string(s.begin() + mL, s.begin() + mR + 1);
	}
};
