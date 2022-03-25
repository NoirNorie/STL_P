// 9093: 단어 뒤집기
// 문자열을 뒤집고 자르고 출력하는 문제

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t; cin.ignore();
    while (t--)
    {
        string s; getline(cin, s);
        reverse(s.begin(), s.end()); // 문자열 뒤집기
        string buf;
        vector<string> vst;
        istringstream ss(s);

        while (getline(ss, buf, ' '))
        {
            vst.push_back(buf);
        }
        string ans = "";
        for (int i = vst.size() - 1; i >= 0; i--)
        {
            ans += vst[i] + " ";
        }
        cout << ans;
        cout << '\n';
    }
}
