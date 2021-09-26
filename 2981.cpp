#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// ���� ��ȣ: 2981(�˹�)
// M���� ���� �������� ��� �����ϰ� �����Ѵ�
// a % M = a - (a/M)*M
// b % M = b - (b/M)*M
// b - a = M * (b/M - a/M)


int gcd(int a, int b) // ��Ŭ���� �˰���
{
	while (b != 0)
	{
		int n = a % b;
		a = b;
		b = n;
	}
	return a;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<long long int> v(N, 0);
	vector<long long int> r;

	// �Է��� �޴´�.
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	// �ִ� ������� ���Ѵ�
	int gc = abs(v[1] - v[0]);
	for (int i = 2; i < v.size(); i++)
	{
		gc = gcd(gc, abs(v[i] - v[i-1]));
	}

	// 2���� ū ���� ���Ѵ�.
	for (int i = 1; i*i <= gc; i++)
	{
		if (gc % i == 0)
		{
			r.push_back(i);
			if (i != gc / i)
			{
				r.push_back(gc / i);
			}
		}
	}

	sort(r.begin(), r.end());
	for (int i = 0; i < r.size(); i++)
	{
		if (r[i] != 1)
			cout << r[i] << " ";
	}


	return 0;
}