#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 2579(계단 오르기)

int dp[301] = { 0 };
int step[301] = { 0 };

inline int MAX(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int N; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> step[i];
	}

	dp[1] = step[1];
	dp[2] = step[1] + step[2];

	for (int i = 3; i <= N; i++)
	{
		dp[i] = MAX(dp[i - 3] + step[i - 1] + step[i], dp[i - 2] + step[i]);
	}

	cout << dp[N] << '\n';


	return 0;
}
