# 2271: 로프

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<int> rope(N);
    for (size_t i = 0; i < rope.size(); i++) cin >> rope[i];
    sort(rope.begin(), rope.end(), greater<int>());
    double m = 0;
    for (size_t i = 0; i < rope.size(); i++) 
    {
        double weight = rope[i] * (i + 1);
        m = max(weight, m);

    }
    cout << (int)m << '\n';
}
