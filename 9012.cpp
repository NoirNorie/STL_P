#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string st;
		stack<char> input;
		int chk = 0;

		cin >> st;

		for (int j = 0; j < st.length(); j++)
		{
			if (st.at(j) == '(') // 여는 괄호라면
			{
				input.push('(');
			}
			else // 닫는 괄호라면
			{
				if (input.empty() == 1) // 닫는 괄호인데 스택이 빔 == 오류
				{
					chk = 1;
					break;
				}
				else // 스택이 비지 않은 상태라면 ( 괄호 하나를 Pop 함
				{
					input.pop();
				}
			}
		}

		if (chk == 1 || input.empty() == 0)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
}