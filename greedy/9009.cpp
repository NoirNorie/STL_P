#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
#include <algorithm>
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
            if (*rviter <= n)
            {
                if (n - *rviter >= 0 && (*rviter != 0))
                {
                    na.push_front(*rviter);
                    n -= *rviter;
                }
                else continue;
            }
        }
        while (na.empty() != true)
        {
            cout << na.front() << " ";
            na.pop_front();
        }
    }
}
