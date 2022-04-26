// 9576: 책 나눠주기
// 논리적으로 맞는데 왜 틀린가 했는데
// 범위하고 인덱스를 잘못 적었다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(pair<int, int> a, pair<int, int> b) 
{
    if (a.second < b.second) return true;
    else {
        if (a.second == b.second) {
            if (a.first < b.first)
                return true;
        }
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        int n, m; 
        cin >> n >> m;

        pair<int, int> vct[1001];
        bool check[1000] = {false};
        
        for (int i = 0; i < m; i++)
        {
            int a, b; cin >> a >> b;
            vct[i] = make_pair( a,b );
        }

        int sum = 0;
        sort(vct, vct + m, cmp);

        for (int i = 0; i < m; i++)
        {
            for (int j = vct[i].first; j <= vct[i].second; j++)
            {
                if (check[j] == false)
                {
                    sum++;
                    check[j] = true;
                    break;
                }
            }
        }

        cout << sum << '\n';
    }
}
