#include <iostream>
#include <string>
using namespace std;

// ���� ��ȣ: 1436(��ȭ���� ��)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int cnt = 0;
	int num = 665;
	string str;

	do
	{
		num++;
		str = to_string(num);
		if (str.find("666") != -1) cnt++;

	} while (cnt != N); // ������� ã�ư��� �Ѵ�

	cout << str << '\n';

	return 0;
}