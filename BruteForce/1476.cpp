// 1476: 날짜 계산

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int e, s, m; cin >> e >> s >> m;
  // 나눠서 떨어지는 경우를 대비하기 위해서 각 경우를 0으로 치환해준다.
  // 나머지가 1인 경우는 이미 존재하므로 1로 지정하면 오답을 유도하게 된다.
	if (e == 15) e = 0;
	if (s == 28) s = 0;
	if (m == 19) m = 0;
	int year = 1;
	while (true)
	{
		if (year % 15 == e && year % 28 == s && year % 19 == m)
		{
			cout << year << '\n';
			break;
		}
		year++;	
	}
}
