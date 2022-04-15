// 2828: 사과 담기 게임
// 직접 움직인다

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m; // 바닥 길이, 바구니 길이 + 바구니의 시작 위치
    int j; cin >> j;        // 사과 개수
    int move = 0;
    int st = m; // 현재 위치
    int ed = (st - m) + 1; // 바구니가 받을 수 있는 끝 범위
    while (j--)
    {
        int a; cin >> a; // 사과가 떨어지는 위치
        if (st < a) // 오른쪽으로 이동해야 하는 경우
        {
            while (st != a)
            {
                st++;
                move++;
            }
            ed = st - m + 1;
        }
        else if (ed > a) // 왼쪽으로 이동해야 하는 경우
        {
            while (ed != a)
            {
                ed--;
                move++;
            }
            st = ed + m - 1;
        }
        else continue;
    }
    cout << move << '\n';

}
