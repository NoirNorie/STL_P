#include <iostream>
using namespace std;

// 문제번호: 2292(벌집)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long T;
	cin >> T;
	
	if (T == 1) // 점화식의 초항
	{
		cout << 1 << '\n';
	}
	else // 점화식을 사용한다
	{
		long long n = 1;
		long long f = 1;

		while (1)
		{
			if (T <= f) break;
			f = f + (6 * n);
			n++;
		}

		cout << n << '\n';
	}

	return 0;
}