// 10824: 네 수
// 여러가지 해봤는데 가장 간단한 방법이 존재했다.

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long a, b, c, d; cin >> a >> b >> c >> d;
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(c) + to_string(d);
    long long n1 = stoll(s1), n2 = stoll(s2);
    cout << n1 + n2 << '\n';
}
