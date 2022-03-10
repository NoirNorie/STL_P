// 2294: 동전 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;


	vector<int> coin(n);
	for (size_t i = 0; i < coin.size(); i++)
	{
		cin >> coin[i];
	}

	sort(coin.begin(), coin.end());
	coin.erase(unique(coin.begin(), coin.end()), coin.end()); // 동전 중복 제거

	vector<int> dp(k + 1, -1); dp[0] = 0; // 기저상태 정의
	for (int i = 1; i <= k; i++)
	{
		int mn = 999999; // 적당히 큰 값을 넣어준다.
		bool chk = false;
		for (size_t j = 0; j < coin.size(); j++)
		{
			if (i - coin[j] < 0) continue;
			else
			{
				if (dp[i - coin[j]] == -1) continue; // 이전 경우가 존재하지 않는 경우를 생각해야 한다.
				chk = true;
				mn = min(mn, dp[i - coin[j]]);
			}
		}
		if (chk == true) dp[i] = mn + 1;
		else dp[i] = -1; // 아예 동작하지 않은 경우 -1을 넣어준다.
	}
	cout << dp[k] << '\n';
}
