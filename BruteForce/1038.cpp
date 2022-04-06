// 1038: 감소하는 수
// 백트래킹을 통한 전수조사 문제
// 문제 범위에 7자리까지 하래서 7자리까지 했지만 테스트 케이스는 훨씬 큰 수까지 포함해야 함
// 열자리 수 까지 해보면 통과함

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

set<string> st;
int k;
bool ext = false;
bool chk = false;
void btrk(string s, int n) // 백트래킹 문자열, , 이번 자리수
{
    if (s.length() == n)
    {
        st.insert(s);
        //for (auto e : st) cout << e << " ";
        //cout << '\n';
        if (st.size() == k+1)
        {
            cout << s << '\n';
            ext = true; chk = true;
            return;
        }
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (s.length() == 0)
        {
            string tmp = "";
            s += to_string(i);
            btrk(s, n);
            s = tmp;
        }
        else if (s[s.length() - 1] - '0' > i)
        {
            string tmp = s;
            s += to_string(i);
            btrk(s, n);
            s = tmp;
        }
        if (ext == true) return;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    for (int i = 1; i <= 10; i++)
    {
        string str = "";
        btrk(str, i);
        if (ext == true) break;
    }
    if (chk == false) cout << -1 << '\n';
}
