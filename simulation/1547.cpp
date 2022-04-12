// 1547: 공

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> vct = { 0,1,2,3 };
    int n; cin >> n;
    while (n--)
    {
        int a, b; cin >> a >> b;
        int tmp = vct[a];
        vct[a] = vct[b];
        vct[b] = tmp;
    }
    for (int i = 1; i <= 3; i++)
    {
        if (vct[i] == 1)
        {
            cout << i << '\n';
            break;
        }
    }
}
