// 2133: 타일 채우기

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> dp(31, 0);
	dp[0] = 1; // 항상 2개의 추가 모형이 생성된다. 이를 처리하기 위한 기저 값
  dp[2] = 3; // 이번 점화식의 기저 상태
	for (int i = 4; i <= n; i++)
	{
		if (i % 2 != 0) continue; // 홀수 크기는 채울 방법이 없다
		else
		{
			dp[i] = (dp[i - 2] * dp[2]);
			for (int j = i - 4; j >= 0; j -= 2)
			{
				dp[i] += dp[j] * 2;
			}
		}
	}
	cout << dp[n] << '\n';
}
