#include <iostream>
#include <vector>
using namespace std;

// 문제번호: 1978(소수 찾기)

int main()
{
	int N, num;
	cin >> N;

	vector<int> v;
	int result = 0;
	int x, chk;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < v.size(); i++)
	{
		x = 2; chk = 0;

		while (v[i] > x)
		{
			if (v[i] == 1 || v[i] % x == 0) // 자신 이전까지 나눠지는 수가 있다면 소수가 아님
			{
				chk++;
				break;
			}
			x++;
				
		}
		if (chk == 0 && v[i] != 1) result++;
	}

	cout << result << endl;

	return 0;
}