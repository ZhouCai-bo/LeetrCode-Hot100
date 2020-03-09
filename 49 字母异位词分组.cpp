class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		map<string, int> m;
		string temp;
		for (auto &a : strs){
			temp = a;
			sort(a.begin(), a.end());
			if (m.find(a) == m.end()){
				res.push_back(vector<string>{temp});
				m.insert(pair<string,int>(a, res.size() - 1));
			}
			else
				res[m[a]].push_back(temp);
		}
		return res;
	}
};
