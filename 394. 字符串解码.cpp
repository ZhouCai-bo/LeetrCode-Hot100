class Solution {
public:
	string decodeString(string s) {
		string res;
		int i = 0;
		while (i<s.size())
		{
			if (isdigit(s[i]))
			{
				int size = i;
				while (s[++size] != '['){}
				int left = size, right = getRight(s, left), num = stoi(s.substr(i, size - i));
				string temp = decodeString(s.substr(left + 1, right - left - 1));
				for (int j = 0; j < num; j++)
					res += temp;
				i = right + 1;
			}
			else if (s[i] == ']')
				++i;
			else
				res += s[i++];
		}
		return res;
	}

	int getRight(string &s, int left)
	{
		int lcnt = 1, rcnt = 0, index = left + 1;
		while (lcnt != rcnt)
		{
			if (s[index] == ']')
				++rcnt;
			else if (s[index] == '[')
				++lcnt;
			++index;
		}
		return index - 1;
	}
};
