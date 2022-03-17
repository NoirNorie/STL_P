// 1051: 숫자 정사각형

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<int>> mp(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		for (size_t j = 0; j < s.length(); j++)
		{
			mp[i][j] = s[j] - '0';
		}
	}
	//for (auto e : mp)
	//{
	//	for (auto z : e)
	//	{
	//		cout << z << " ";
	//	}
	//	cout << '\n';
	//}

	int mx = 0;
	for (size_t i = 0; i < mp.size(); i++)
	{
		for (size_t j = 0; j < mp[i].size(); j++)
		{
			int t = 0;
			int c = mp[i][j];
			while (i + t < n && j + t < m)
			{
				if (c == mp[i + t][j] && c == mp[i][j + t] && c == mp[i + t][j + t]) mx = max(mx, t+1);
				t++;
			}
		}
	}
	cout << mx * mx << '\n';

}
