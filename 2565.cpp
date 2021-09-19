#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 2565(전기줄)

inline int MAX(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int N; cin >> N;
	vector<pair<int, int>> v(N + 1, make_pair(0, 0));
	vector<int> dp(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());
	// 주어진 입력에서 가장 긴 부분 증가 수열을 만든다
	// 임의의 순서로 들어온 입력에 대해서 정렬을 수행해야 한다.
	// pair 객체도 내장 함수가 sort 해준다.

	dp[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= N; j++)
		{
			if (v[j].second < v[i].second)
			{
				dp[i] = MAX(dp[i], dp[j] + 1);
			}
		}
	}

	int tmp = 0;
	for (int i = 1; i <= N; i++)
	{
		tmp = MAX(tmp, dp[i]);
	}
	// 가장 긴 부분 증가 수열을 제외한 나머지 값들은 수열의 값과 교차하게 된다.
	// 교차하는 부분을 제거해서 출력해준다.

	cout << v.size() - tmp - 1 << '\n';
	// 벡터를 1부터 입력받았으므로 -1을 해준다.

	return 0;
}
