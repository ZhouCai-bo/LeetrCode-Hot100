class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (auto a : s)
		{
			if (!st.empty() && ((st.top() == '(' && a == ')') || (st.top() == '[' && a == ']') || (st.top() == '{' && a == '}')))
				st.pop();
			else
				st.push(a);

		}
		if (!st.empty())
			return false;
		return true;
	}
};
