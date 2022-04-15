// 2012: 등수 매기기
// 수학적으로 증명된 개념이 있는데 자세히 기억나지 않는다

#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> na;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> vct(n, 0);
    for (int i = 0; i < n; i++) cin >> vct[i];
    sort(vct.begin(), vct.end());

    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += abs(i - vct[i-1]);
    }
    cout << sum << '\n';
}
