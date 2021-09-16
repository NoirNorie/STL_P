#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// 문제 번호: 1463(1로 만들기)

vector<int> Memo(pow(10, 6) + 1, -1);

inline int MIN(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	Memo[1] = 0; // 1은 연산할 필요 없이 1이다.
	Memo[2] = 1; Memo[3] = 1; // 명확한 답은 미리 기록해 놓는다.

	for (int i = 4; i <= N; i++)
	{
		if (i % 3 == 0 && i % 2 == 0) // 6의 배수인 경우도 생각하자
		{
			int tmp = MIN(Memo[i / 3] + 1, Memo[i / 2] + 1);
			Memo[i] = MIN(tmp, Memo[i - 1] + 1);
		}
		else if (i % 3 == 0) Memo[i] = MIN(Memo[i / 3] + 1, Memo[i - 1] + 1);
		else if (i % 2 == 0) Memo[i] = MIN(Memo[i / 2] + 1, Memo[i - 1] + 1);
		else Memo[i] = Memo[i - 1] + 1;
	}

	cout << Memo[N] << '\n';
	
	return 0;

}