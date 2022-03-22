// 2167: 2차원 배열의 합
// DP문제는 아니지만 DP로 해결함

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= m; j++)
        {
            int x; cin >> x;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + x;
        }
    }
    int t; cin >> t;
    while (t--)
    {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        int sum = dp[y2][x2] - dp[y2][x1 - 1] - dp[y1 - 1][x2] + dp[y1 - 1][x1 - 1];
        cout << sum << '\n';
    }

}
