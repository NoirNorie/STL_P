// 11057: 오르막 수

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	
	if (n == 1) cout << 10 % 10007<< '\n';
	else if (n == 2) cout << 55 % 10007<< '\n';
	else
	{
		vector<vector<long long>> dp(n, vector<long long>(10, 0));
		for (int i = 0; i < 9; i++) dp[0][i] = 1;
		for (int i = 0; i < n; i++)
		{
			dp[i][0] = 1;
			dp[i][9] = 1;
		}
		dp[0][9] = 10; // 기저 상태

		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				dp[i][j] = (dp[i][j - 1] % 10007) + (dp[i - 1][j] % 10007);
				dp[i][9] += dp[i][j] % 10007;
			}
		}

		long long answer = 0;
		for (auto e : dp) answer += e[9] % 10007;

		cout << answer % 10007;

	}
}

// 테이블을 작성할 수만 있다면 생각보다 쉬운 문제
// 가장 어려웠던 것은 나머지 연산 빼먹어서 틀린 것을 인지하는 것
