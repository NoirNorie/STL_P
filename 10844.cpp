#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define m 1000000000

// 문제 번호: 10844(쉬운 계단 수)

int main()
{
	int N; cin >> N;

	int DP[101][10] = { 0 };
	long long int sum = 0;

	for (int i = 1; i <= 9; i++)
	{
		DP[1][i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				DP[i][j] = DP[i - 1][j + 1] % m;
			}
			else if (j == 9)
			{
				DP[i][j] = DP[i - 1][j - 1] % m;
			}
			else
			{
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % m;
			}
		}
	}
	for (int i = 0; i <= 9; i++)
	{
		sum = (sum + DP[N][i]) % m;
	}
	cout << sum << '\n';

	return 0;
}