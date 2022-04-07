// 1373: 2진수 8진수
// 진법 변환
// 마지막에 0 처리를 안해줘서 한 번 틀렸다

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s; cin >> s; int len = s.length() - 1;
    int cnt = 0, num = 0;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (cnt < 2)
        {
            num += (s[len - i] - '0') * pow(2, cnt++);
        }
        else
        {
            num += (s[len - i] - '0') * pow(2,cnt);
            ans += to_string(num);
            num = 0; cnt = 0;
        }
    }
    if (num != 0) ans += to_string(num);
    if (ans.length() == 0) cout << 0 << '\n';
    else
    {
        ans = string(ans.rbegin(), ans.rend());
        cout << ans << '\n';
    }
}
