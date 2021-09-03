#include <iostream>
#include <cmath>
#include <deque>
using namespace std;


// 문제 번호: 4948(베르트랑 공준)

int main()
{
	int N;

	do
	{
		cin >> N;
		if (N == 0) break;

		int cnt = 0, flag = 0;
		int up = N * 2;
		int down = N + 1; // 자기 자신은 포함하지 않는다.
		deque<int> dq;

		int max = sqrt(up); // 여기까지는 확인해 봐야 함
		int num = 2; // 2부터 확인한다.

		for (int i = down; i <= up; i++)
		{
			if (i == 1) flag = 1; // 1은 소수가 아님
			else
			{
				for (num = 2; num <= max; num++)
				{
					if (i != num && i % num == 0)
					{
						flag = 1; break; // 자기 자신을 제외하고 나눠지면 소수가 아님
					}
				}
			}	
			if (flag == 0) cnt++;
			flag = 0;
		}

		cout << cnt << '\n';

	} while (N != 0);

	return 0;
}