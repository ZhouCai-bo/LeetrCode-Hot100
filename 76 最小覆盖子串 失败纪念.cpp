class Solution {
public:
	string minWindow(string s, string t) {
		int s_size = s.size(), t_size = t.size();
		pair<char, int>currL, currR;
		vector<int> word(t_size, -1);
		string temp = t;
		int i = 0, Gmin = -1, mL, mR, cnt = 0;
		for (; i < s_size; i++){
			int index = temp.find(s[i]);
			if (index != -1){
				if (cnt==0){
					currL.first = s[i];
					mL = currL.second = i;
				}
				word[index] = i;
				temp[index] = '#';
				cnt++;
				if (cnt == t_size){
					currR.first = s[i];
					mR = currR.second = i;
					Gmin = mR - mL;
					break;
				}
			}
		} 
		for (i = word[findMinValue(word)] + 1; i < s_size; i++){
			int index = findMinIndex(word, t, s[i]);
			if (index != -1){
				word[index] = i;
				if (s[i] == currL.first){
					index = findMinValue(word);
					currL.first = t[index];
					currL.second = word[index];
					if (currR.second<i){
						currR.first = s[i];
						currR.second = i;
					}
					int len = currR.second - currL.second;
					if (Gmin > len){
						Gmin = len;
						mL = currL.second;
						mR = currR.second;
					}
				}
			}
		}
		if (Gmin == -1)
			return "";
		return string(s.begin() + mL, s.begin() + mR + 1);
	}

	int findMinIndex(vector<int> &word, string t, char ch)
	{
		int min = INT_MAX, curr = 0, minIndex = -1;
		while ((curr = t.find(ch)) < t.size())
		{
			t[curr] = '#';
			if (word[curr] < min)
			{
				min = word[curr];
				minIndex = curr;
			}
		}
		return minIndex;
	}
	int findMinValue(vector<int> &word)
	{
		int min = word[0], index = 0;
		for (int i = 1; i < word.size(); i++)
		{
			if (word[i] < min)
			{
				min = word[i];
				index = i;
			}
		}
		return index;
	}
}; 
