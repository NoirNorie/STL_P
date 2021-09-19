#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

	cout << v.size() - tmp - 1 << '\n';

	return 0;
}