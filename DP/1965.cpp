// 1965: 상자넣기
// 문제의 조건을 제대로 안읽었다.
// 맨 마지막 값이 아니라 최대 값을 구하는 것이었음

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
    vector<int> vct(n);
    for (int i = 0; i < n; i++) cin >> vct[i];
    vector<int> dp(n, 1);
    int mx = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vct[j] < vct[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        mx = max(dp[i], mx);
    }
    cout << mx << '\n';
}
