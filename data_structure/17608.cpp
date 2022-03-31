// 17608: 막대기
// 스택을 이용하면 쉽게 수행 가능하다.

#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (stk.empty() == true) stk.push(x);
        else
        {
            while (stk.empty() != true)
            {
                if (stk.top() <= x)
                {
                    stk.pop();
                }
                else break;
            }
            stk.push(x);
        }
    }
    cout << stk.size() << '\n';
}
