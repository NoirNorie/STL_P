// 2740: 행렬 곱셈
// 간단함

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, k; cin >> n >> m;
    vector<vector<int>> vct1(n, vector<int>(m));
    for (size_t i = 0; i < vct1.size(); i++)
    {
        for (size_t j = 0; j < vct1[i].size(); j++)
        {
            cin >> vct1[i][j];
        }
    }
    cin >> m >> k;
    vector<vector<int>> vct2(m, vector<int>(k));
    for (size_t i = 0; i < vct2.size(); i++)
    {
        for (size_t j = 0; j < vct2[i].size(); j++)
        {
            cin >> vct2[i][j];
        }
    }
    vector<vector<int>> ans(n, vector<int>(k, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int t = 0; t < m; t++)
            {
                ans[i][j] += (vct1[i][t] * vct2[t][j]);
            }
        }
    }
    for (auto e : ans)
    {
        for (auto z : e)
        {
            cout << z << " ";
        }
        cout << '\n';
    }
}
