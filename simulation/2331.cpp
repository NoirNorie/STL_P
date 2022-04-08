// 2331: 반복수열

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int dp[10];          // 제곱 값을 보관할 배열
map<string, int> mp; // 수열을 보관할 맵
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a; int p; cin >> a >> p;
    for (int i = 1; i <= 9; i++) dp[i] = pow(i, p); // 연산량을 줄이기 위해 제곱값을 보관한다.
    
    mp.insert({ a, 1 });
    while (true)
    {
        string tmp = ""; int sum = 0;
        for (size_t i = 0; i < a.length(); i++) sum += dp[a[i] - '0'];
        tmp += to_string(sum);
        auto miter = mp.find(tmp); // 매번 find 함수를 사용해서 찾아내는 것이 아니라 이터레이터를 사용해서 연산을 줄인다.
        if (miter == mp.end()) mp.insert({ tmp, 1 });
        else
        {
            if (miter->second <= 2) miter->second++; // 반복되지 않는 수도 있으므로 2번 나타나는지 확인해봐야 한다.
            else break; // 만약 어떠한 수가 3번째 등장한다면 그 수부터 반복되는 수열이 시작되므로 더 이상 연산할 필요 없다
        }
        a = tmp;
    }
    
    int cnt = 0;
    for (auto e : mp) if (e.second == 1) cnt++; // 맵에 기록된 숫자 중 한 번 삽입된 숫자들만 찾아내면 된다.

    cout << cnt;
}
