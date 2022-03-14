// 2847: 게임을 만든 동준이

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
	int cnt = 0;
	int idx = v.size() - 2;
	while(idx >= 0)
	{
		if (v[idx] >= v[idx + 1])
		{
			v[idx]--;
			cnt++;
		}
		else idx--;
	}
	cout << cnt << '\n';
}
