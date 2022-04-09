// 2851: 슈퍼 마리오
// 범위도 작고 고려할 것도 적은 간단한 완전탐색 문제

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int m[10];
pair<int, int> mx = { 999, 0 }; // 차이, 점수 순서쌍

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 10; i++) cin >> m[i];
    
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += m[i];
        int tmp = abs(100 - sum);
        if (tmp < mx.first) mx = { tmp, sum };
        else if (tmp == mx.first)
        {
            if (sum >= mx.second) mx = { tmp, sum };
        }

    }
    cout << mx.second << '\n';
}
