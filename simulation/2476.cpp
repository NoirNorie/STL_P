// 2476: 주사위 게임

#include <iostream>
#include <cmath>
using namespace std;
int mx = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    while(n--)
    {
        int a, b, c; cin >> a >> b >> c;
        int sum = 0;
        if (a == b && b == c && c == a) sum = 10000 + (a * 1000);
        else if (a == b && a != c) sum = 1000 + (a * 100);
        else if (b == c && b != a) sum = 1000 + (b * 100);
        else if (c == a && c != b) sum = 1000 + (c * 100);
        else sum = max(max(a, b), c) * 100;
        mx = max(mx, sum);
    }
    cout << mx << '\n';
}
