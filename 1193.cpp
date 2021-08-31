#include <iostream>
using namespace std;

// 문제번호: 1193(분수 찾기)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long T;
	cin >> T;

	if (T == 1)
	{
		cout << 1 << "/" << 1 << '\n';
	}
	else
	{
		long long sum = 1; // 갯수
		long long p = 1; // 증가량
		int x = 2; // 분수의 합계

		// 대략적인 위치를 찾아낸다.
		do
		{
			p++; x++;
			sum = sum + p;
		} while (T > sum);

		// 상세한 위치를 찾아간다.
		int u = 1, d = p;
		if (x % 2 == 0) //올라가는 순서
		{
			for (int k = sum; k > T; k--)
			{
				d--; u++;
			}
			cout << u << "/" << d << '\n';
		}
		else //내려가는 순서
		{
			for (int k = sum; k > T; k--)
			{
				d--; u++;
			}
			cout << d << "/" << u << '\n';
		}
	}
	return 0;
}