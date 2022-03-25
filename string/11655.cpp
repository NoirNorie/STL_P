// 11655: ROT13
// 뭐가 문제인지 모르겠는데 원래 풀었던 방법이 제대로 안먹힌다.

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s; 
    getline(cin, s); 
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (s[i] + 13 > 'Z') cout << char(s[i] - 13);
            else cout << char(s[i] + 13);
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (s[i] + 13 > 'z') cout << char(s[i] - 13);
            else cout << char(s[i] + 13);
        }
        else cout << char(s[i]);
        i++;
    }
}
