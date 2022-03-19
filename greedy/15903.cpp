// 15903: 카드 합체 놀이
// 자료형을 잘 맞추자

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, t; cin >> n >> t;
	vector<long long> vc(n);
	for (size_t i = 0; i < vc.size(); i++) cin >> vc[i];

	while (t--)
	{
		sort(vc.begin(), vc.end());
		long long tmp = vc[0] + vc[1];
		vc[0] = vc[1] = tmp;
	}
	long long ans = 0;
	for (auto e : vc) ans += e;
	cout << ans << '\n';
	
}
