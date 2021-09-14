#include <iostream>
using namespace std;

// 문제 번호: 9184(신나는 함수 실행)

int memo[102][102][102] = { 0 }; // 기록 배열

int w(int a, int b, int c)
{
	if (memo[50+a][50+b][50+c] != 0) // 계산 기록이 존재할 경우
	{
		return memo[50 + a][50 + b][50 + c];
	}
	else // 계산한 기록이 없으면 구해야 한다.
	{
		if (a <= 0 || b <= 0 || c <= 0)
		{
			if (memo[50 + a][50 + b][50 + c] == 0)
			{
				memo[50 + a][50 + b][50 + c] = 1;
			}
			return 1;
		}
		else if (a > 20 || b > 20 || c > 20)
		{
			if (memo[50 + a][50 + b][50 + c] == 0)
			{
				memo[50 + a][50 + b][50 + c] = w(20, 20, 20);
			}
			return w(20, 20, 20);
		}
		else if (a < b && b < c)
		{
			if (memo[50 + a][50 + b][50 + c] == 0)
			{
				memo[50 + a][50 + b][50 + c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
			}
			return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		}
		else
		{
			if (memo[50 + a][50 + b][50 + c] == 0)
			{
				memo[50 + a][50 + b][50 + c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
			}
			return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c;

	do
	{
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) break; // 탈출 조건

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';

	} while (1);

	return 0;
}