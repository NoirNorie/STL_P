#include <iostream>
using namespace std;

// 문제번호: 1712(손익분기점)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long result;
	long long A, B, C;
	// A는 고정 비용 (고정)
	// B는 가변 비용 (1개를 제작하는데 드는 비용)
	// C는 판매 가격 

	cin >> A >> B >> C;

	long long profit = C - B;

	if (profit <= 0) // 가변 비용이 판매 가격보다 크거나 같은 경우 절대 손익 분기를 넘길 수 없음
	{
		cout << -1 << '\n';
	}
	else
	{
		result = (A / profit) + 1; // 이익이 나는 지점은 0보다 커져야 하므로 + 1 함
		cout << result << '\n';
	}
	return 0;
	

	// 루프 문으로는 20억까지 할 경우 타임아웃에 걸린다.
}