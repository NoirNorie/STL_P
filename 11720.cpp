#include <iostream>
#include <string>
using namespace std;

// ���� ��ȣ: 11720

int main()
{
	int N; cin >> N; // ������ ���� �Է�
	string x; cin >> x;
	int sum = 0;
	for (int i = 0; i < x.length(); i++)
	{
		sum += (x[i] - 48);
	}

	cout << sum << '\n';

	return 0;
}