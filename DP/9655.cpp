// 9655: 돌 게임
// DP 문제라는데 맞나 싶다.

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	if (n == 1) cout << "SK" << '\n';
	else if (n == 2) cout << "CY" << '\n';
	else
	{
		if (n % 2 == 1) cout << "SK";
		else cout << "CY";
	}

}
