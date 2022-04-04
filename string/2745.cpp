// 2745: 진법 변환

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s; int n;
    cin >> s >> n;
    long long x = 0;
    int len = s.length() - 1;
    for (int i = 0; i <= len; i++)
    {
        if (isdigit(s[len - i]))
        {
            int tmp = s[len - i] - '0';
            x += pow(n, i) * tmp;
        }
        else
        {
            int tmp = s[len - i] - 'A' + 10;
            x += pow(n, i) * tmp;
        }
    }
    cout << x << '\n';
}
