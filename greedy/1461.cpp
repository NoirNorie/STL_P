// 1461: 도서관

#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> posbooks; // 양수 방향
deque<int> negbooks; // 음수 방향

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    while (n--)
    {
        int a; cin >> a;
        if (a > 0) posbooks.push_back(a);
        else negbooks.push_back(a);
    }
    sort(posbooks.begin(), posbooks.end());
    sort(negbooks.begin(), negbooks.end());
    int cost = 0;
    // 더 먼쪽은 왕복하지 않도록 지정한다.
    if (posbooks.empty())
    {
        cost += abs(negbooks.front());
        for (int i = 0; i < m; i++)
        {
            if (negbooks.empty()) break;
            negbooks.pop_front();
        }
    }
    else if (negbooks.empty())
    {
        cost += abs(posbooks.back());
        for (int i = 0; i < m; i++)
        {
            if (posbooks.empty()) break;
            posbooks.pop_back();
        }
    }
    else
    {
        if (abs(posbooks.back()) > abs(negbooks.front()))
        {
            cost += abs(posbooks.back());
            for (int i = 0; i < m; i++)
            {
                if (posbooks.empty()) break;
                posbooks.pop_back();
            }
        }
        else
        {
            cost += abs(negbooks.front());
            for (int i = 0; i < m; i++)
            {
                if (negbooks.empty()) break;
                negbooks.pop_front();
            }
        }
    }

    while (negbooks.empty() != true)
    {
        cost += abs(negbooks.front()) * 2;
        for (int i = 0; i < m; i++)
        {
            if (negbooks.empty()) break;
            negbooks.pop_front();
        }
    }
    while (posbooks.empty() != true)
    {
        cost += abs(posbooks.back()) * 2;
        for (int i = 0; i < m; i++)
        {
            if (posbooks.empty()) break;
            posbooks.pop_back();
        }
    }
    cout << cost << '\n';
}
