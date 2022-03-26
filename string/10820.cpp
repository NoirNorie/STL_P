// 10820: 문자열 분석
// 입력만 잘 처리받으면 된다.

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string str;
    while (true)
    {
        
        getline(cin, str);
        if (str.length() == 0) break; // 입력이 없으면 종료

        int a = 0, b = 0, c = 0, d = 0;

        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ') d++;
            else if (isdigit(str[i])) c++;
            else if (isupper(str[i])) b++;
            else a++;
        }

        cout << a << " " << b << " " << c << " " << d << '\n';


    }
}
