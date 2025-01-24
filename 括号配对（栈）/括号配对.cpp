#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> m;
		bool is;
		for (char c : s) {
			switch (c) {
			case('('):
				m.push(c);
				break;
			case('['):
				m.push(c);
				break;
			case('{'):
				m.push(c);
				break;
			case(')'):
				if (m.empty()) {
					return 0;
				}
				if (m.top() != '(') {
					return 0;
				}
				else if (m.top() == '(') {
					m.pop();
				}
				break;
			case('}'): 
				if (m.empty()) {
					return 0;
				}
				if (m.top() != '{') {
					return 0;
				}
				else if (m.top() == '{') {
					m.pop();
				}
				break;
			case(']'):
				if (m.empty()) {
					return 0;
				}
				if (m.top() != '[') {
					return 0;
				}
				else if (m.top() == '[') {
					m.pop();
				}
				break;
			}
		}
		if (!m.empty()) {
			return 0;
		}
		else {
			is = 1;
		}
		return is;
	}
};
int main()
{
	string s;
	cin >> s;
	Solution solution;
	bool b = solution.isValid(s);
	cout << b;
	return 0;
}