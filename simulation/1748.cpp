// 1748: 수 이어쓰기 1
// 신기한 방법이 존재했다

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long n; cin >> n;
    long long r = 0;
    for (long long x = 1; x <= n; x *= 10)
    {
        r += n - x + 1;
    }
    cout << r;
}
