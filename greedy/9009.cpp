// 9009: 피보나치
// 간만에 그리디 문제

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque<long long> na;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<long long> dp(2, 0);
    dp[0] = 0; dp[1] = 1;
    while (true)
    {
        int x = dp.size();
        long long c = dp[x - 1] + dp[x - 2];
        if (c > 1000000000) break;

        dp.push_back(c);
    }

    int t; cin >> t;
    while (t--)
    {
        long long n; cin >> n;

        vector<long long>::reverse_iterator rviter;;
        for (rviter = dp.rbegin(); rviter != dp.rend(); rviter++)
        {
            // 최소 개수를 만들려면 큰 수부터 빼면 된다.
            if (*rviter <= n)
            {
                if (n - *rviter >= 0 && (*rviter != 0)) // 음수가 되어서는 안되며 0을 추가할 필요도 없다
                {
                    na.push_front(*rviter);
                    n -= *rviter;
                }
                else continue;
            }
        }
        while (na.empty() != true) // 덱을 사용하여 앞에서부터 값을 추가했으므로 앞에서부터 빼낸다.
        {
            cout << na.front() << " ";
            na.pop_front();
        }
    }
}
