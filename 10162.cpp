# 10162: 전자레인지

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
 
    if (T % 10 != 0) // 맞추기 불가능한 경우
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << T / 300 << ' ';
        T %= 300;
        cout << T / 60 << ' ';
        T %= 60;
        cout << T / 10 << ' ';
        T %= 10;
    } // 동전 거스르기를 빠르게 푸는 방법이 있었다.
    
}
