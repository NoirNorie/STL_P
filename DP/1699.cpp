// 1699: 제곱수의 합

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> dp(100001, 0);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    dp[1] = 1; dp[2] = 2; dp[3] = 3;

    int s = 1;
    int nextPow = pow(s+1, 2);

    for (int i = 4; i <= n; i++)
    {
        if (i == nextPow) // 제곱수인 경우 무조건 1이 된다.
        {
            dp[i] = 1;
            s++;
            nextPow = pow(s + 1, 2);
        }
        else
        {
            int mini = 100001; // 적당히 큰 수랑 비교한다
            for (int j = s; j > 0; j--) // 다음 제곱값 이전의 모든 경우에 대해서 생각한다.
            {
                int idx = pow(j, 2);
                mini = min(mini, dp[idx] + dp[i - idx]);
            }
            // 41의 경우 36(6^2) + 5 보다 25(5^2) + 16(4^2)가 더 적은 숫자를 요구한다.      
            dp[i] = mini;
        }
    }
    cout << dp[n] << '\n';
}
