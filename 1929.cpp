#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// ���� ��ȣ: 1929(�Ҽ� ���ϱ�)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	vector<int> v;

	for (int i = 1; i <= N; i++)
	{
		v.push_back(i);
	} // �ϴ� ���ڸ� �� ����ִ´�.

	v[0] = 0; // 1�� �Ҽ��� �ƴϹǷ� �̸� �����Ѵ�.

	int max = sqrt(N); // ���غ��� �ϴ� �ִ� ����
	int x = 2; // 2�� ������� �����.
	while (x <= max)
	{
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i] == 0) continue; // ������ �ʿ���� ���� ���� �Ѱܹ�����.
			if (v[i] != x && v[i] % x == 0) v[i] = 0;
		}
		x++;
	}

	for (int i = M - 1; i < v.size(); i++)
	{
		if (v[i] != 0)
		{
			cout << v[i] << '\n';
		}	
	}

	return 0;
}