#include <iostream>
#include <vector>
using namespace std;


// ���� ��ȣ: 1010 (�ٸ� ����)
// ���հ� ���õ� ���� ��ȹ�� ����
// ������ ���� �� �ϳ�: (n C r) = (n-1 C r-1) + (n-1 C r)

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
			if (n == m || n == 0 || m == 0) // ������ ���ڰ� ������ ������ �Ұ����ϹǷ� �ϳ��� ��츸 ����
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