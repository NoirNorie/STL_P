#include <iostream>
#include <vector>
using namespace std;


// 문제 번호: 1010 (다리 놓기)
// 조합과 관련된 동적 계획법 문제
// 조합의 성질 중 하나: (n C r) = (n-1 C r-1) + (n-1 C r)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	int dp[31][31] = { 0, };

	for (int n = 0; n <= 30; n++)
	{
		for (int m = 0; m <= 30; m++)
		{
			if (n == m || n == 0 || m == 0) // 지점의 숫자가 같으면 교차가 불가능하므로 하나의 경우만 존재
			{
				dp[n][m] = 1;
			}
			else
			{
				dp[n][m] = dp[n - 1][m - 1] + dp[n - 1][m];
			}

		}
	}

	for (int i = 0; i < T; i++)
	{
		int N, M;
		cin >> N >> M;
		
		cout << dp[M][N] << '\n';

	}

	return 0;
}