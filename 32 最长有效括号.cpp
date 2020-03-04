class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> res(s.size(), 0);
		stack<int> left;
		int max = 0, curr = 0;
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '(')
				left.push(i);
			else if (s[i] == ')' && !left.empty()){
				res[left.top()] = 1;
				res[i] = 1;
				left.pop();
			}
			else
				continue;
		}
		for (int i = 0; i <= s.size(); i++){
			if (i == s.size() || res[i] == 0){
				max = (max>curr ? max : curr);
				curr = 0;
			}
			else
				curr += res[i];
		}
		return max; 
	}
};
