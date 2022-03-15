// 10988: 팰린드롬인지 확인하기

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s; cin>> s;
    bool chk = true;
    for(size_t i = 0 ; i < s.length()/2; i++)
    {
        if(s[i] != s[(s.length()-1) - i]) chk = false;
    }
    if(chk) cout << 1 << '\n';
    else cout << 0 << '\n';
}
