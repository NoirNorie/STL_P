#include <iostream>
#include <cmath>
using namespace std;

// 문제 번호: 5086(배수와 약수)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;
	do
	{
		cin >> a >> b;

		if (a == 0 && b == 0) break;

		if (a % b == 0)
		{
			cout << "multiple" << '\n';
		}
		else if (b % a == 0)
		{
			cout << "factor" << '\n';
		}
		else
		{
			cout << "neither" << '\n';
		}

	} while (1);

	return 0;
}