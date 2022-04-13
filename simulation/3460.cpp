// 3460: 이진수

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        long long a; cin >> a;
        string s = "";
        while(a > 0)
        {
            if (a % 2 != 0) s += "1";
            else s += "0";
            a /= 2;
        }
        for (size_t i = 0; i < s.length(); i++) // 안뒤집어도 된다.
        {
            if (s[i] == '1') cout << i << " ";
        }

    }
}
