// 10819: 차이를 최대로

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	vector<int> v(n);
	for (size_t i = 0; i < v.size(); i++) cin >> v[i];
	sort(v.begin(), v.end());
	int mx = 0;
	do
	{
		int cnt = 0;
		for (size_t i = 0; i < v.size() - 1; i++)
		{
			cnt += abs(v[i] - v[i + 1]);
		}
		mx = max(mx, cnt);

	} while (next_permutation(v.begin(), v.end()));

	cout << mx << '\n';
}
