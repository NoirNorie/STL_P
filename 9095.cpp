#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 9095(1, 2, 3 ���ϱ�)

vector<int> dp(12, 0);

int main()
{
	dp[1] = 1; dp[2] = 2; dp[3] = 4; // �ʱⰪ

	int T; cin >> T;
	while (T--)
	{
		int n; cin >> n;

		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		cout << dp[n] << '\n';
	}

	return 0;
}