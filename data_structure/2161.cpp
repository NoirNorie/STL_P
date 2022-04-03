// 2161: 카드 1
// 간단한 덱 문제

#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) dq.push_back(i);

    while (dq.size() > 1)
    {
        cout << dq.front() << " ";
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout << dq.front() << '\n';

}
