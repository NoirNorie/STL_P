#include <iostream>
using namespace std;

// ������ȣ: 1712(���ͺб���)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long result;
	long long A, B, C;
	// A�� ���� ��� (����)
	// B�� ���� ��� (1���� �����ϴµ� ��� ���)
	// C�� �Ǹ� ���� 

	cin >> A >> B >> C;

	long long profit = C - B;

	if (profit <= 0) // ���� ����� �Ǹ� ���ݺ��� ũ�ų� ���� ��� ���� ���� �б⸦ �ѱ� �� ����
	{
		cout << -1 << '\n';
	}
	else
	{
		result = (A / profit) + 1; // ������ ���� ������ 0���� Ŀ���� �ϹǷ� + 1 ��
		cout << result << '\n';
	}
	return 0;
	

	// ���� �����δ� 20����� �� ��� Ÿ�Ӿƿ��� �ɸ���.
}