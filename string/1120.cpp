// 1120: 문자열
// 순서쌍을 이용해서 다른 인덱스에서 카운트 하는 방법을 생각했는데 그럴 필요 없었다
// 생각보다 간단했음

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    

    string x, y; cin >> x >> y;
    int xlen = x.length();
    int ylen = y.length();
    // 무조건 x가 짧거나 같다.
    int mn = 50;
    
    for (int i = 0; i + xlen <= ylen; i++)
    {
        string subs = y.substr(i, xlen);
        int cnt = 0;
        for (size_t j = 0; j < subs.length(); j++)
        {
            if (subs[j] != x[j]) cnt++; // 다른 알파벳의 수를 센다
        }
        mn = min(mn, cnt); //
    }
    cout << mn << '\n';
    
}
