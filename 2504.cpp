#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	long long result = 0;
	int temp = 1;
	bool flag = false;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			temp *= 2;
			st.push('(');
		}
		else if (s[i] == '[')
		{
			temp *= 3;
			st.push('[');
		}
		else if (s[i] == ')' && (st.empty() || st.top() != '('))
		{
			flag = true;
			break; // 불가능한 경우 탈출해버린다.			
		}
		else if (s[i] == ']' && (st.empty() || st.top() != '['))
		{
			flag = true;
			break; // 불가능한 경우 탈출해버린다.		
		}
		else if (s[i] == ')')
		{
			if (s[i - 1] == '(') 
				result += temp;
			st.pop();
			temp /= 2;
		}
		else if (s[i] == ']')
		{
			if (s[i - 1] == '[') 
				result += temp;
			st.pop();
			temp /= 3;
		}
	}
	if (flag || !st.empty())
	{
		cout << 0 << '\n';
	}
	else
	{
		cout << result << '\n';
	}
	
	return 0;
}