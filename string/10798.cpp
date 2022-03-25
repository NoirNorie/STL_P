// 10798: 세로읽기
// 범위를 틀려서 에러가 출력된다. 범위를 잘 지키자

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<string> svt = {};
    for (int i = 0; i < 5; i++)
    {
        string s; cin >> s;
        svt.push_back(s);
    }
    string ans = "";
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (svt[j].length()-1 < i) continue;
            ans += svt[j][i];
        }
    }
    cout << ans;
}
