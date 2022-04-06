// 1159: 농구 경기
// 간단한 구현 문제

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> vct(26, 0);
    while (n--)
    {
        string s; cin >> s;
        vct[s[0] - 'a']++;
    }
    string tmp = "";
    for (int i = 0; i < vct.size(); i++)
    {
        if (vct[i] >= 5)
            tmp += 'a' + i;
    }
    if (tmp.length() == 0) cout << "PREDAJA" << '\n';
    else cout << tmp << '\n';
}
