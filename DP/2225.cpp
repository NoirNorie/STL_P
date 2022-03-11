// 2225: 합분해

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;

	vector<vector<long long>>dp(k, vector<long long>(n+1, 1));
	for (int i = 1; i < k; i++)
	{
		for (int j = 1; j <=n ; j++)
		{
			dp[i][j] = dp[i - 1][j]% 1000000000 + dp[i][j - 1] % 1000000000;
		}
	}
	cout << dp[k-1][n] % 1000000000 << '\n';
}

// 문제 조건을 잘 읽자
// % 1000000000
