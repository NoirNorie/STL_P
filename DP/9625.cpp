// 9625: BABBA
// 간단한 DP 문제

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int, int>> dp(n+1); // A개수, B개수 순서 쌍
    dp[0] = { 1, 0 }; // 기저 값

    for (int i = 1; i <= n; i++)
    {
        dp[i].first = dp[i - 1].second;
        dp[i].second = dp[i - 1].first + dp[i - 1].second;
    }

    cout << dp[n].first << " " << dp[n].second << '\n';

}
