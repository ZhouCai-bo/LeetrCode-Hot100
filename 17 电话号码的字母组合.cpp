class Solution {
public:
	vector<string> res;
	vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return res;
		vector<string> strs{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		recurse(strs, digits, 0, "");
		return res;
	}
	void recurse(vector<string> &strs, string &digits, int index, string temp){
		if (index >= digits.size()){
			res.push_back(temp);
			return;
		}
		string curr = strs[digits[index] - 48 - 2];
		for (int i = 0; i < curr.size(); i++)
			recurse(strs, digits, index + 1, temp+curr[i]);
	}
};
