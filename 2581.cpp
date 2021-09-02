#include <iostream>
using namespace std;

// 문제 번호: 2581(소수)

int main()
{
	int M, N;
	int sum = 0, min = 0, flag = 0;
	int i;
	cin >> M;
	cin >> N;

	int chk = N;

	while (chk >= M)
	{
		i = 2; flag = 0;
		
		if (chk == 1)
		{
			chk--; continue;
		}
		while (chk > i)
		{		
			if (chk % i == 0) // 나눠지면 소수가 아님
			{
				flag = 1;
				break;
			}
			i++;
		}
		if (flag == 0) // 소수가 아니라면
		{
			min = chk; // 최소 값으로 지정한다
			sum += chk; // 합계를 구한다.
		}
		
		chk--;
	}
	if (min == 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << sum << '\n';
		cout << min << '\n';
	}

	return 0;
}