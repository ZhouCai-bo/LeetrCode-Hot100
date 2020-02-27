class Solution {
public:
	int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
		map<char,int> had;
		vector<int> res(s.size(), 1);
		int max = 1;
		had.insert(make_pair(s[0],0));
		for (int i = 1; i < s.size(); i++){
			//未重复
			if (had.find(s[i]) == had.end()){
				res[i] += res[i - 1];
				had.insert(make_pair(s[i], i));
				max = max>res[i] ? max : res[i];
			}
			//重复
			else{
				res[i] = i - had[s[i]];
				for (int j = 0; j <= res[i - 1] - res[i]; j++)
					had.erase(s[i - res[i] - j]);
				had.insert(make_pair(s[i], i));

			}
		}
		return max;
	}
};
