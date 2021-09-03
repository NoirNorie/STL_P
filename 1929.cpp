#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// 문제 번호: 1929(소수 구하기)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	vector<int> v;

	for (int i = 1; i <= N; i++)
	{
		v.push_back(i);
	} // 일단 숫자를 다 집어넣는다.

	v[0] = 0; // 1은 소수가 아니므로 미리 제거한다.

	int max = sqrt(N); // 구해봐야 하는 최대 숫자
	int x = 2; // 2의 배수부터 지운다.
	while (x <= max)
	{
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i] == 0) continue; // 연산이 필요없는 경우는 빨리 넘겨버린다.
			if (v[i] != x && v[i] % x == 0) v[i] = 0;
		}
		x++;
	}

	for (int i = M - 1; i < v.size(); i++)
	{
		if (v[i] != 0)
		{
			cout << v[i] << '\n';
		}	
	}

	return 0;
}