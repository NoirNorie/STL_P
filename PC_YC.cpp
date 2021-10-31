#include <iostream>
#include <string>
using namespace std;

bool rec(string inp, int s)
{
	if (s == 1)
	{
		return true;
	}
	else
	{

		// 회문 검사
		for (int i = 0; i < s / 2; i++)
		{
			if (inp[i] != inp[s - 1 - i])
			{
				return false;
			}
		}
		// 회문이라면
		if (s % 2 == 0) // 길이가 짝수라면
		{
			if (rec(inp.substr(0, s / 2), s / 2) == true && rec(inp.substr((s / 2), -1), s / 2) == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else // 길이가 홀수라면
		{
			if (rec(inp.substr(0, s / 2), s / 2) == true && rec(inp.substr((s / 2)+1, -1), s / 2) == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	}
}

int main()
{
	string inp; cin >> inp;
	int len = inp.length();

	if (rec(inp, len) == true)
		cout << "AKARAKA" << '\n';
	else
		cout << "IPSELENTI" << '\n';
}