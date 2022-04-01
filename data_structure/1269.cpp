// 1269: 대칭 차집합
// 

#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

set<int> a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        b.insert(x);
    }
    int cnt = 0;
    for (auto e : a)
    {
        if (b.find(e) == b.end()) cnt++;
    }

    for (auto e : b)
    {
        if (a.find(e) == a.end()) cnt++;
    }
    cout << cnt << '\n';

}
