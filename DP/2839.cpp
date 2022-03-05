#2839: 설탕 배달 - 동적 계획법

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n; cin >> n;
	int cnt = 0;
	vector<long long> dp(5001, -1);
	dp[3] = 1; dp[5] = 1; // 기저 상태

	if (n <= 5) cout << dp[n] << '\n';
	else
	{
		for (int i = 6; i <= n; i++)
		{			
			if (dp[i - 5] != -1 && dp[i - 3] != -1) dp[i] = min(dp[i - 5], dp[i - 3]) + 1;
			else if (dp[i - 5] == -1 && dp[i - 3] != -1) dp[i] = dp[i - 3] + 1;
			else if (dp[i - 5] != -1 && dp[i - 3] == -1) dp[i] = dp[i - 5] + 1;
		}
		cout << dp[n] << '\n';
	}
}
