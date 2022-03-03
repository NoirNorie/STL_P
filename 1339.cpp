# 1339: 단어 수학

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int T; cin >> T;
    vector<int> alp(26, 0);
    vector<string> s(T);

    int N = 9;
    for (size_t i = 0; i < s.size(); i++) cin >> s[i];
    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = 0; j < s[i].length(); j++)
        {
            alp[s[i][j] - 'A'] += pow(10, s[i].length() - j - 1);
        }
    }
    sort(alp.begin(), alp.end(), greater<int>());
    
    int i = 0, answer = 0;
    while (N > 0 && alp[i] != 0)
    {
        answer += alp[i++] * (N--);
    }
    cout << answer << '\n';
}
