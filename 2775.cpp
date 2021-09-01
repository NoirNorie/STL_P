#include <iostream>
using namespace std;

// 문제번호: 2775(부녀회장이 될테야)
// 메모이제이션을 사용할 경우 속도 상승을 노릴 수 있을 것으로 예상됨

int Level(int k, int n)
{
	if (k == 0) return n;
	else if (n == 1) return 1;
	else return Level(k, n - 1) + Level(k - 1, n);
}

int main()
{
	int k, n, T;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> k;
		cin >> n;

		cout << Level(k, n) << '\n';
	}

	return 0;
}