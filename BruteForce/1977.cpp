// 1977: 완전제곱수

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int m, n; cin >> m >> n;
	vector<int> vc(n+1, 0);
	int i = 1;

	while (true)
	{
		long long x = pow(i, 2);
		if (x > n) // 제곱 값이 범위를 이탈한다면
		{
			int sum = 0;
			int mn = 0;
			for (int i = m; i <= n; i++)
			{
				if (vc[i] != 0) sum += vc[i];
				if (mn == 0) mn = vc[i];
			}
			if (sum == 0) cout << -1 << '\n';
			else
			{
				cout << sum << '\n';
				cout << mn << '\n';
			}
			break;
		}
		else vc[x] = x;
		i++;
	}
}
