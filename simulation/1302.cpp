// 1302: 베스트셀러
// 맵을 이용한 간단한 구현 문제

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> mp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	while (n--)
	{
		string s; cin >> s;

		auto miter = mp.find(s);
		if (miter != mp.end()) miter->second++;
		else mp.insert({ s,1 });
	}
	int mx = 0; string s = "";
	for (auto e : mp)
	{
		if (e.second > mx)
		{
			s = e.first;
			mx = e.second;
		}
	}
	cout << s << '\n';
}
