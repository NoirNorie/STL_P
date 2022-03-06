# 1212 : 8진수 2진수
# 문제가 더럽다

#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

deque<string> dq;

int main()
{
	string in; cin >> in;

	if (in == "0") cout << 0 << '\n';
	else
	{
		string answer, bef;
		// 진수 변환
		string::reverse_iterator rsiter;
		for (rsiter = in.rbegin(); rsiter != in.rend(); rsiter++)
		{
			int i = 2;
			string tmp = "000";
			int a = *rsiter - '0';
			while (a > 0)
			{
				tmp[i--] = (a % 2) + '0';
				a /= 2;
			}
			dq.push_front(tmp);
		}

		for (auto e : dq) answer += e;

		for (size_t i = 0; i < answer.length(); i++)
		{
			if (answer[i] != '0')
			{
				cout << answer.substr(i);
				break;
			}
		}
	}

}
