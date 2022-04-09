// 10448: 유레카 이론
// 진정한 의미의 완전탐색 문제
// 3중 for문을 이용해서 모든 경우를 검사하는 문제

#include <iostream>
#include <vector>
using namespace std;

vector<int> dp; // 삼각수를 보관할 벡터

bool BF(int x)
{
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp.size(); j++)
        {
            for (int k = 1; k < dp.size(); k++)
            {
                if (dp[i] + dp[j] + dp[k] == x) return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp.push_back(0); dp.push_back(1);
    while (dp[dp.size() - 1] < 1000) dp.push_back(dp[dp.size() - 1] + dp.size());
    
    int n; cin >> n;
    while (n--)
    {
        int t; cin >> t;
        cout << BF(t) << '\n';
    }
}
