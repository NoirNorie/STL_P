// 1251: 단어 나누기

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

set<string> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;

	for (int i = 1; i < s.length(); i++)
	{
		for (int j = 1; j < s.length(); j++)
		{
			if (i + j >= s.length()) break;
			string a = s.substr(0, i), b = s.substr(i, j), c = s.substr(i + j);

			if (a.length() < 1 || b.length() < 1 || c.length() < 1) continue;
			a = string(a.rbegin(), a.rend());
			b = string(b.rbegin(), b.rend());
			c = string(c.rbegin(), c.rend());
			string tmp = a + b + c;
			st.insert(tmp);
		}
	}
	cout << *st.begin() << '\n'; // 세트 가장 앞에 있는 값이 가장 빠른 값
}
