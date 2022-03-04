# 12865: 평범한 배낭

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> bag(n+1, vector<int>(m+1, 0));
	vector<vector<int>> v(n+1, vector<int>(2, 0));
	for (size_t i = 1; i < v.size(); i++) cin >> v[i][0] >> v[i][1]; // 무게, 가치 입력
	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++)
	{
		int weight = v[i][0], value = v[i][1]; // 현재 물건의 무게와 가치
		for (int j = 1; j <= m; j++) // 무게 반복
		{
			if (v[i][0] <= j) //현재 담을 수 있는 무게라면
			{
				bag[i][j] = max(bag[i - 1][j], bag[i - 1][j - weight] + value);
			}
			else
			{
				bag[i][j] = bag[i - 1][j];
			}
		}
	}
	cout << bag[n][m] << '\n';

}
