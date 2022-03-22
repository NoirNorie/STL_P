// 2577: 숫자의 개수

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;
	long long res = a * b * c;
	string s = to_string(res);
	vector<int> sc(10, 0);
	for (size_t i = 0; i < s.length(); i++)
	{
		int x = s[i] - '0';
		sc[x]++;
	}
	for (auto e : sc)
	{
		cout << e << '\n';
	}
}
