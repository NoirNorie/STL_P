// 2935: 소음
// 조건 하나를 생각하지 않아서 한 번 틀렸었다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string a, b, c;  cin >> a >> b >> c;

	if (b == "*")
	{
		string result = "1";
		for (size_t i = 0; i < a.length() - 1 + c.length() - 1; i++) result += "0";
		cout << result;
	}
	else
	{
		string result;
		if (a.length() > c.length())
		{
			result = a; result[result.length() - c.length()] = '1';
		}
		else if (a.length() < c.length())
		{
			result = c; result[result.length() - a.length()] = '1';
		}
		else
		{
			result = c; result[0] = '2';
		}
		cout << result;
	}

}
