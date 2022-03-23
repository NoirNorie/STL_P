// 2493: 탑
// 스택을 이용하는 문제

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

stack<pair<int, int>> stk; // 스택

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        while (stk.empty() != true)
        {

            if (stk.top().second > x)
            {
                cout << stk.top().first << " ";
                break;
            }
            stk.pop();
        }
        if (stk.empty()) cout << 0 << " ";
        stk.push({ i, x });
    }
}
