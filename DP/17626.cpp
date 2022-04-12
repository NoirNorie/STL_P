// 17626: Four Squares
// 접근 방법이 생각보다 어렵다

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1; // 기저상태
    for (int i = 2; i <= n; i++)
    {
        int mini = dp[i - 1] + 1;
        for (int j = 1; j * j <= i; j++)
        {
            mini = min(mini, dp[i - j * j]);
        }
        dp[i] = mini + 1;
    }
    cout << dp[n] << '\n';

}
