// 11048: 이동하기

#include <iostream>
#include <vector>
using namespace std;

inline int DP_max(int a, int b, int c)
{
    return ((a > b ? a : b) > (a > c ? a : c) ? (a > b ? a : b) : (a > c ? a : c));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); // 이 부분 빼먹으니까 150ms 정도 느려졌음
    
    int n, m; cin >> n >> m;
    vector<vector<int>> maze(n+1, vector<int>(m+1, 0));
    for (size_t i = 1; i < maze.size(); i++) 
        for (size_t j = 1; j < maze[i].size(); j++) cin >> maze[i][j];

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (size_t i = 1; i < dp.size(); i++)
        for (size_t j = 1; j < dp[i].size(); j++)
            dp[i][j] = DP_max(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + maze[i][j];

    cout << dp[n][m];

}
