// 7567: 그릇
// 스택을 이용한 간단한 문제

#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> stk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s; cin >> s;
    int cnt = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (stk.empty() == true)
        {
            stk.push(s[i]);
            cnt += 10; // 처음에는 무조건 10cm 올라간다.
        }
        else
        {
            if ((s[i] == '(' && stk.top() == '(') ||
                (s[i] == ')' && stk.top() == ')')) // 방향이 같으면 포개진다.
            {
                stk.push(s[i]);
                cnt += 5;
            }
            else
            {
                stk.push(s[i]);
                cnt += 10;
            }
        }
    }
    cout << cnt << '\n';

}
