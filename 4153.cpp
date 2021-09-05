#include <iostream>
#include <cmath>
using namespace std;

// 문제 번호: 4153(직각 삼각형)

int main()
{
	int a, b, c;

	do
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;

		if (a > b)
		{
			if (a > c)
			{
				if (pow(a, 2) == pow(b, 2) + pow(c, 2)) cout << "right" << '\n';
				else cout << "wrong" << '\n';
			}
			else
			{
				if (pow(c, 2) == pow(a, 2) + pow(b, 2)) cout << "right" << '\n';
				else cout << "wrong" << '\n';
			}
		}
		else if (b > c)
		{
			if (pow(b, 2) == pow(a, 2) + pow(c, 2)) cout << "right" << '\n';
			else cout << "wrong" << '\n';
		}
		else
		{
			if (pow(c, 2) == pow(a, 2) + pow(b, 2)) cout << "right" << '\n';
			else cout << "wrong" << '\n';
		}

	} while (1);

	return 0;
}