// 1357: 뒤집힌 덧셈
// 문자열을 조작하는 간단한 문제

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    string a, b; cin >> a >> b;
    a = string(a.rbegin(), a.rend());
    b = string(b.rbegin(), b.rend());
    string tmp = to_string(stoi(a) + stoi(b));
    tmp = string(tmp.rbegin(), tmp.rend());
    cout << stoi(tmp);

}
