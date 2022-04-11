// 2525: 오븐 시계
// 정답률이 낮길래 풀어봤다

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >> c;
    a = (a + (b + c) / 60) % 24;
    int minute = (b + c) % 60;
    cout << a << " " << minute << '\n';
}
