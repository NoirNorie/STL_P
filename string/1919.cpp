// 1919: 애너그램 만들기

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    int cnt = a.length() + b.length();

    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i] == b[j])
            {
                a[i] = -1; b[j] = -2;
                cnt -= 2;
            }
        }
    }
    cout << cnt << '\n';

}
