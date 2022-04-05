// 2846: 오르막길
// 간단한 구현 문제

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int mx = 0;
    int n; cin >> n;
    vector<int>vct(n);
    for (size_t i = 0; i < vct.size(); i++) cin >> vct[i];

    for (size_t i = 0; i < vct.size(); i++)
    {
        int current = vct[i], cnt = 0;
        int start = vct[i];
        for (size_t j = i+1; j < vct.size(); j++)
        {
            if (current < vct[j]) current = vct[j];
            else if (current >= vct[j]) break;
        }
        mx = max(mx, current - start);
    }
    cout << mx << '\n';
}
