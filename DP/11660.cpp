// 11660: 구간 합 구하기 5
// 정신없네

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	vector<vector<long long int>> vc(n + 1, vector<long long int>(n + 1, 0));
	vector<vector<long long int>> xy(k, vector<long long int>(4, 0));
	for (size_t i = 1; i < vc.size(); i++)
	{
		for (size_t j = 1; j < vc[i].size(); j++)
		{
			int p; cin >> p;
			if (i == 1 && j == 1) vc[i][j] = p;
			else if (i == 1 && j > 1) vc[i][j] = vc[i][j - 1] + p;
			else if (j == 1 && i > 1) vc[i][j] = vc[i - 1][j] + p;
			else vc[i][j] = vc[i - 1][j] + vc[i][j - 1] - vc[i - 1][j - 1] + p;
		}
	}
	while (k--)
	{
		int a, b, c, d; cin >> a >> b >> c >> d;
		cout << vc[c][d] - vc[a - 1][d] - vc[c][b-1] + vc[a-1][b-1] << '\n';

	}
}
