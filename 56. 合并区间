class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int i = 0, j;
		bool tag;
		while (i < intervals.size()){
			tag = 0;
			j = i + 1;
			while (j < intervals.size()){
				int ileft = intervals[i][0], iright = intervals[i][1];
				int jleft = intervals[j][0], jright = intervals[j][1];
				if (ileft <= jright && iright >= jleft){
					intervals.erase(intervals.begin() + j);
					ileft = jleft < ileft ? jleft : ileft;
					iright = jright > iright ? jright : iright;
					intervals[i][0] = ileft;
					intervals[i][1] = iright;
					tag = 1;
				}
				j++;
			}
			if (!tag)
				i++;
		}
		return intervals;
	}
}; 
