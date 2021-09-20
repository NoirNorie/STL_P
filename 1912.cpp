#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 1912 (연속합)


inline int MAX(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> v(N + 1, -1001); // 입력 배열
	vector<int> calc(N + 1, -1001);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	calc[1] = v[1]; // 일단 숫자 하나는 골라야 하므로 지정한다

	int Result = -1001;
	for (int i = 1; i <= N; i++)
	{
		calc[i] = MAX(v[i],calc[i-1] + v[i]);
		Result = MAX(Result, calc[i]);
	}

	cout << Result << '\n';

	return 0;
}

