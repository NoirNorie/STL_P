#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k; cin >> n >> k;

    vector<int> dp(k + 1, 0);

    vector<int> vct(n+1);
    for (int i = 1; i <= n; i++)
        cin >> vct[i];

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= vct[i])
            {
                dp[j] += dp[j - vct[i]];
            }
        }
    }

    cout << dp[k] << '\n';

    return 0;
}
