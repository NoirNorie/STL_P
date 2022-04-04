// 14659: 한조서열정리하고옴ㅋㅋ
// 그럭저럭 풀만한 문제인데 문제 문항을 너무 초등학생같이 적어서 보기가 싫은 문제

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> vct(n);
    for (size_t i = 0; i < vct.size(); i++) cin >> vct[i];

    int mx = 0, cnt = 0;
    int current = vct[0];
    for (size_t i = 1; i < vct.size(); i++)
    {
        if (vct[i] > current)
        {
            mx = max(mx, cnt);
            cnt = 0;
            current = vct[i];
        }
        else
        {
            cnt++;
        }
    }
    mx = max(mx, cnt);
    cout << mx << '\n';
}
