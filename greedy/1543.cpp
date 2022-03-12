// 1543: 문서 검색

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str; getline(cin, str, '\n');	
	string srch; getline(cin, srch, '\n');
	int srch_len = srch.length();
	int mx = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		int cnt = 0;
		for (size_t j = i; j < str.length();)
		{
			if (str.substr(j, srch_len) == srch)
			{
				j += srch_len;
				cnt++;
			}
			else j++;
		}
		mx = max(mx, cnt);
	}
	cout << mx << '\n';
}
