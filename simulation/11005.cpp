// 11005: 진법 변환 2
// 숫자로 표현이 가능한 경우에 대해서 처리를 안해줘서 한 번 틀렸다.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string tmp = "";
    long long n, b;
    cin >> n >> b;
    while (n > 0)
    {
        if (n % b > 9)  tmp += 'A' + (n % b) - 10; // 숫자로 표현이 불가능한 경우
        else tmp += to_string(n % b); // 숫자로 표현이 가능한 경우 숫자를 문자열로 변환해서 넣어줘야 한다.
        n /= b;
    }
    string ans(tmp.rbegin(), tmp.rend()); // 반대로 집어넣었으므로 역순으로 바꾼다.
    cout << ans << '\n';
}
