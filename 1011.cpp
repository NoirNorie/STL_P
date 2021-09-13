#include <iostream>
#include <cmath>
using namespace std;

// 문제 번호: 1011(Fly me to the Alpha centauri)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int j = 0; j < T; j++)
	{
		long long x, y;
		cin >> x >> y;

		y -= x;
		long long i = 1;
		long long sum = 0;

		while (y > sum + i*2)
		{
			sum += i * 2;
			i++;
		}
		if (sum + i >= y) cout << 2*i - 1 << '\n';
		else cout << 2*i << '\n';

	}

	return 0;
}
