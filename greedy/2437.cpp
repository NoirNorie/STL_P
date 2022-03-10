// 2437: 저울

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> v(n);
	for (size_t i = 0; i < v.size(); i++) cin >> v[i];
	
	sort(v.begin(), v.end());
	if (v[0] != 1) cout << 1 << '\n';
	else
	{
		int sum = 0;
		for (int i = 0; i <= n; i++)
		{
			if (v[i] > sum + 1) break; // 합산값 다음 수보다 큰 수가 나온다면 찾아낸 것
			sum += v[i];
		}
		cout << sum + 1 << '\n';
	}
}
