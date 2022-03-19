// 2810: 컵홀더

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	string tmp = "";
	for (size_t i = 0; i < s.length(); i++)
	{
		if (i == 0)
		{
			if (s[i] == 'S') tmp += "*S*";
			else
			{
				tmp += "*LL*";
				i++;
			}
		}
		else
		{
			if (s[i] == 'S') tmp += "S*";
			else
			{
				tmp += "LL*";
				i++;
			}
		}
	}
	int cnt = 0;
	for (size_t i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] != 'S' && tmp[i] != 'L') continue;
		else // 좌석에 대해서
		{
			if (tmp[i - 1] == '*')
			{
				tmp[i - 1] = '0';
				cnt++;
			}
			else if (tmp[i + 1] == '*')
			{
				tmp[i + 1] = '0';
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}
