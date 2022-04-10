// 13410: 거꾸로 구구단

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int mx = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k; cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		string s = to_string(i * n);
		int num = stoi(string(s.rbegin(), s.rend()));
		mx = max(mx, num);
	}

	cout << mx << '\n';
}
