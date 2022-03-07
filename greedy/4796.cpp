#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int L, P, V;
	int i = 1;
	while (1)
	{
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;

		int cnt = 0;
		while (V > 0)
		{
			if (V < L) // 남은 휴가 일수가 연속일보다 작은 경우
			{
				cnt += V;
				break;
			}
			else
			{
				cnt += L; // 사용 가능 일을 추가한다
				V -= P;
			}
		}
		cout << "Case " << i++ << ": " << cnt << '\n';
	}
}
