// 2696: 중앙값 구하기
// 최대, 최소 힙을 이용한 중간값 구하기 문제

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 중간 값을 담을 벡터
vector<int> midvals;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int cnt = 1;
        midvals.clear();
        // 최대 힙과 최소 힙도 초기화 해준다.
        priority_queue<int, vector<int>, less<int>> mxpq;
        priority_queue<int, vector<int>, greater<int>> mnpq;
        while (n--)
        {
            int x; cin >> x;
            // 최소, 최대 힙을 이용한 중간 값 구하기
            /*
                1: 최대 힙의 크기는 최소합의 크기와 같거나 하나 더 커야함
                2: 최대 힙의 최대 원소 <= 최소 힙의 최소 원소
                3: 이 규칙에 맞지 않는다면 최소 힙과 최대 힙의 가장 위의 값을 교환한다
            */
            if (mxpq.empty() == true) mxpq.push(x);
            else if (mxpq.size() == mnpq.size()) mxpq.push(x);
            else mnpq.push(x);

            if (mnpq.empty() != true && mxpq.empty() != true && mxpq.top() > mnpq.top())
            {
                int mx = mxpq.top(); mxpq.pop();
                int mn = mnpq.top(); mnpq.pop();

                mxpq.push(mn);
                mnpq.push(mx);
            }
            if (cnt % 2 != 0)
            {
                midvals.push_back(mxpq.top());
            }
            cnt++;
        }
        cout << midvals.size() << '\n';
        for (auto e : midvals) cout << e << " ";
        cout << '\n';
    }
    
}
