#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 11504(���� �� ������� ����)
// LIS ���� - DP Ǯ�̹�

inline int MAX(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int N; cin >> N;
	vector<int> v(N+1, 0);
	vector<int> up(N+1, 0);
	vector<int> dn(N+1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	for (int i = 1; i <= N; i++)
	{
		up[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (v[j] < v[i]) // �����ϴ� �κ��̶��
			{
				up[i] = MAX(up[i], up[j] + 1); // �� �� �κ� ���� ������ ���غ���
			}
		}
	}

	for (int i = N; i >= 1; i--)
	{
		dn[i] = 1;
		for (int j = N; j >= i ;j--)
		{
			if (v[i] > v[j]) // �����ϴ� �κ��̶��
			{
				dn[i] = MAX(dn[i], dn[j] + 1);
			}
		}
	}

	int result = 0;
	for (int i = 0; i <= N; i++)
	{
		result = MAX(result, up[i] + dn[i] - 1);
	}
	cout << result<< '\n';


	return 0;
}