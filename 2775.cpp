#include <iostream>
using namespace std;

// ������ȣ: 2775(�γ�ȸ���� ���׾�)
// �޸������̼��� ����� ��� �ӵ� ����� �븱 �� ���� ������ �����

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