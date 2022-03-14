// 1449: 수리공 항승

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (size_t i = 0; i < v.size(); i++) cin >> v[i];
	sort(v.begin(), v.end());

	int c = v[0];
	int cnt = 1;
	for (size_t i = 1; i < v.size(); i++)
	{
		if (c + k > v[i]) continue;
		else
		{
			c = v[i];
			cnt++;
		}
	}
	cout << cnt << '\n';
}
