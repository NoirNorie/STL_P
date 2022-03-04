# 1110 : 더하기 사이클

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int x = n, a, b, ns;
    int t = 0;
    do
    {
        ++t;
        a = n / 10;
        b = n % 10;
        ns = a + b;
        n = (b * 10) + (ns % 10);
        
    } while (x != n);

    cout << t << '\n';
}
