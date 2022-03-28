// 5557: 1학년
// 생각보다 복잡한 문제
// 다시 풀어봐야겠다

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

    vector<int> nums(n);
    for (size_t i = 0; i < nums.size(); i++) cin >> nums[i];
    vector<vector<long long>> vct(n, vector<long long>(21, 0)); // 결과를 담아낼 벡터

    vct[0][nums[0]] = 1; // 기저상태
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (vct[i - 1][j] > 0)
            {
                if (j - nums[i] >= 0) vct[i][j - nums[i]] += vct[i - 1][j];
                if (j + nums[i] <= 20) vct[i][j + nums[i]] += vct[i - 1][j];
            }
        }
    }

    cout << vct[n - 2][nums[n - 1]] << '\n';


}
