// 2920: 음계

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool chk = false;
    vector<int> vct(8);
    for (size_t i = 0; i < vct.size(); i++) cin >> vct[i];
    size_t i = 1;
    for (i; i < vct.size(); i++)
    {
        if (i == 1) // 오름 내림 결정
        {
            if (vct[i - 1] < vct[i]) chk = true;
            else chk = false;
        }
        else
        {
            if (chk == true && vct[i - 1] > vct[i]) break;
            else if (chk == false && vct[i - 1] < vct[i]) break;
        }
    }
    if (i != 8) cout << "mixed";
    else
    {
        if (chk == true) cout << "ascending";
        else cout << "descending";
    }

}
