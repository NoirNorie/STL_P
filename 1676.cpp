#include <iostream>
#include <cmath>
using namespace std;

// ���� ��ȣ: 1676(���丮�� 0�� ����)

// ���ڸ��� 0 �� ���÷��� 2�� 5�� �����ų� 10�� ���;� �Ѵ�.
// �ڿ������� ��� ��쿡�� 5���� 2�� ���� �����ϹǷ� 2�� ������ �� �ʿ� ����.
// ���Ϸ��� ���ڱ��� 5�� ������ ������ ��

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n; cin >> n;
	int sum = 0;

	while (n >= 5)
	{
		sum += n / 5;
		n /= 5;
	}

	cout << sum << '\n';


	return 0;
}