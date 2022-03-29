// 12904: A와 B
// 문자열을 가지고 해결하는 그리디 알고리즘 문제
// 그리디 인가 싶기도 하지만 그리디 분류에 속해 있었음

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    

    string a, b; cin >> a >> b;
    while (b.length() > a.length() && a != b)
    {
        int bE = b.length() - 1; // b의 마지막 인덱스를 가리킬 변수
        if (b[bE] == 'A')
        {
            b = b.substr(0, bE);
        }
        else
        {
            b = b.substr(0, bE);
            b = string(b.rbegin(), b.rend());
        }
    }

    if (a == b)cout << 1 << '\n';
    else cout << 0 << '\n';
}
