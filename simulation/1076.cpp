// 1076: 저항
// 하드 코딩으로 해결함

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    string x = "";
    for (int i = 0; i < 2; i++)
    {
        string a; cin >> a;
        if (a == "black") x += "0";
        else if (a == "brown") x += "1";
        else if (a == "red") x += "2";
        else if (a == "orange") x += "3";
        else if (a == "yellow") x += "4";
        else if (a == "green") x += "5";
        else if (a == "blue") x += "6";
        else if (a == "violet") x += "7";
        else if (a == "grey") x += "8";
        else x += "9";
    }
    string a; cin >> a;
    long long ans;
    if (a == "black") ans = 1;
    else if (a == "brown") ans = 10;
    else if (a == "red") ans = 100;
    else if (a == "orange") ans = 1000;
    else if (a == "yellow") ans = 10000;
    else if (a == "green") ans = 100000;
    else if (a == "blue") ans = 1000000;
    else if (a == "violet") ans = 10000000;
    else if (a == "grey") ans = 100000000;
    else ans = 1000000000;
    ans *= stoll(x);
    cout << ans << '\n';

}
