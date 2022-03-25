// 2875: 대회 or 인턴
// 너무 대충 풀었더니 많이 틀렸다
// 예외 사항과 범위를 간과했다

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, i; cin >> n >> m >> i;
    int cnt = 0;
    while (i--)
    {
        if (n / 2 < m) m--;
        else n--;
    }
    while (n >= 2 && m >= 1)
    {
        n -= 2;
        m--;
        cnt++;
    }
    cout << cnt << '\n';
}
