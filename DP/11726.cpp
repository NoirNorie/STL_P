# 11726: 타일링

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	vector<int> dp(n + 1, 0);
	dp[1] = 1; dp[2] = 2; // 기저 상태
	if (n <= 2) cout << dp[n] % 10007;
	else
	{
		for (int i = 3; i <= n; i++)
		{
			dp[i] = (dp[i - 1]%10007) + (dp[i - 2]%10007);
		}
		cout << dp[n] % 10007;
	}

}
