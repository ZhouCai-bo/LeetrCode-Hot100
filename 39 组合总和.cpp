class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		recurse(candidates, target, 0, 0, vector<int>());
		return res;
	}
	void recurse(vector<int>& candidates, int target, int index, int curr, vector<int> temp){
		if (curr == target){
			res.push_back(temp);
			return;
		}
		if (curr > target || index >= candidates.size())
			return;
		temp.push_back(candidates[index]);
		recurse(candidates, target, index, curr + candidates[index], temp);
		temp.pop_back();
		recurse(candidates, target, index + 1, curr, temp);
	}
};
