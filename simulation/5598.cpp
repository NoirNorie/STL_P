// 5598: 카이사르 암호
// 잊을법하면 나타난다

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a; cin >> a;
    for (size_t i = 0; i < a.length(); i++)
    {
        if (a[i] - 3 < 'A') a[i] = 'Z' - ('A' - a[i] + 2);
        else a[i] -= 3;
    }
    cout << a << '\n';
}
