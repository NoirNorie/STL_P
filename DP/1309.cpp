// 1309: 동물원

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long n; cin >> n;
	//vector<vector<unsigned long long>> dp(100001, vector<unsigned long long>(4,0));
	//dp[1][1] = 1, dp[1][2] = 1, dp[1][3] = 1;
	//dp[1][0] = 3;
//
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i][3] = (dp[i - 1][0] % 9901) % 9901;
//		dp[i][2] = ((dp[i][3] % 9901) % 9901 - (dp[i - 1][2] % 9901) % 9901) % 9901;
//		dp[i][1] = ((dp[i][3] % 9901) % 9901 - (dp[i - 1][1] % 9901) % 9901) % 9901;
//		dp[i][0] = ((dp[i][1] % 9901) % 9901 + (dp[i][2] % 9901) % 9901 + (dp[i][3] % 9901) % 9901) % 9901;
//	}
//	cout << dp[n][0] % 9901 << '\n'; // 이렇게 풀어도 점화식은 맞는데 오버플로 문제를 해결하지 못함

	vector<long long> dp(1000001, 0);
	dp[0] = 1; dp[1] = 3;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = (((dp[i - 1] * 2) % 9901) + (dp[i - 2]%9901)) % 9901;
	}
	cout << dp[n] << '\n';
}
