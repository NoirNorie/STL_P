// 10871: X보다 작은 수
// 간단한 구현 문제

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, x; cin >> n >> x;
    vector<int> vct;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if (a < x) vct.push_back(a);
    }
    for (auto e : vct) cout << e << " ";

}
