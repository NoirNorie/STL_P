#include <iostream>
using namespace std;

// 문제 번호: 1629(곱셈)

long long int Div(long long int A, long long int B, long long int C)
{
	if (B == 1) // 분할이 완료되었다면
	{
		return A % C;
	}
	else // 추가 분할이 필요하다면
	{
		long long int result = Div(A, B / 2, C);
		if (B % 2 != 0) // 절반으로 쪼개지지 않는다면
		{
			return result % C * result % C * (A % C) % C; // 오버플로를 방지하기 위해서 %C를 또 해줘야 한다.
		}
		else // 절반으로 쪼개진다면
		{
			return result % C * result % C;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long int A, B, C;
	cin >> A >> B >> C;

	cout << Div(A,B,C) << '\n';

	return 0;
}