#include <iostream>
using namespace std;

// 문제 번호: 11653(소인수분해)

int main()
{
	int N;
	cin >> N;

	if (N == 1)
	{
		return 0;
	}
	else
	{
		int d = 2;

		while (N >= d)
		{
			if (N % d == 0) // 나눠진다면
			{
				cout << d << '\n'; // 나눈 수를 한번 출력한다
				N = N / d; // 다음 N은 나눠진 수
			}
			else // 나눠지지 않는다면
			{
				d++; // 다음 수로 넘어간다
			}
		}
	}

	return 0;
}