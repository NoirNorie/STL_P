// 1620: 나는야 포켓몬 마스터
// 비정렬 맵을 사용하여 풀이함
// 메모리도 속도도 준수한 편인것 같음

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> name_poke;
unordered_map<int, string> num_poke;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		string s; cin >> s;
		name_poke.insert({ s, i });
		num_poke.insert({ i, s });
	}

	for (int i = 0; i < k; i++)
	{
		string s; cin >> s;
		if (isdigit(s[0])) // 숫자인지 아닌지 판별한다
		{
			cout << num_poke.find(stoi(s))->second << '\n';
		}
		else
		{
			cout << name_poke.find(s)->second << '\n';
		}

	}
}
