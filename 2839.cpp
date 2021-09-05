#include <iostream>
using namespace std;

// 문제 번호: 2839(설탕 배달)

int calc(int N)
{
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			if ((i * 3) + (j * 5) == N)
			{
				return i + j;
			}
		}
	}
	return -1;
}

int main()
{
	int N;
	cin >> N;

	cout << calc(N) << endl;
}
