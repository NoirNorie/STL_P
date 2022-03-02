# 1026 - 보물

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    long long ans = 0;
    vector<int> A(N), B(N);
    for (size_t i = 0; i < N; i++) cin >> A[i];
    for (size_t i = 0; i < N; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for (size_t i = 0; i < N; i++) ans += (A[i] * B[i]);

    cout << ans << '\n';
}
