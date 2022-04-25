// 16212: 정열적인 정렬
// 내일 시험 잘보게 해주세요

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> vct(n);
    for (size_t i = 0; i < vct.size(); i++) cin >> vct[i];

    sort(vct.begin(), vct.end());

    for (auto e : vct) cout << e << " ";
}
