// 1343: 폴리오미노
// 사전 순으로 앞선 것 = A가 먼저 채워지면 된다
// 4와 2에 대해서만 처리하면 된다
// X의 개수가 홀수 = 무조건 -1을 출력하면 됨

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string a; cin >> a;
    string s = "";
    int alen = a.length(), cnt = 0;
    bool chk = false;
    for (int i = 0; i < alen; i++)
    {
        if (a[i] == 'X')
        {
            cnt++;
            if (cnt == 4)
            {
                s += "AAAA";
                cnt = 0;
            }
        }
        else
        {
            if (cnt % 2 != 0)
            {
                chk = true;
                break;
            }
            if (cnt == 4) s += "AAAA";
            else if (cnt == 2) s += "BB";
            s += '.';
            cnt = 0;
        }
    }
    if (chk == true) cout << -1 << '\n';
    else
    {
        if (cnt % 2 != 0) cout << -1 << '\n';
        else
        {
            if (cnt == 4) s += "AAAA";
            else if (cnt == 2) s += "BB";
            cout << s << '\n';
        }
    }
}
