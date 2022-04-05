// 17413: 단어 뒤집기 2
// 덱과 스트링을 이용하여 문제를 풀었다.

#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

deque<char> dq;
string ans = "";
void eject()
{
    while (dq.empty() != true)
    {
        ans += dq.front(); dq.pop_front();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    getline(cin, s);
    auto siter = s.begin();
    bool transition = true;

    while (siter != s.end())
    {
        if (*siter == ' ')
        {
            eject();
            ans += *siter;
        }
        else
        {
            if (*siter == '<')
            {
                eject();
                dq.push_back(*siter);
                transition = false;
            }
            else if (*siter == '>')
            {
                dq.push_back(*siter);
                eject();
                transition = true;
            }
            else if (transition == true) dq.push_front(*siter);
            else dq.push_back(*siter);
        }
        siter++;
    }
    eject();

    cout << ans << '\n';
}
