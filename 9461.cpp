#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 9461(�ĵ��� ����)

vector<long long int> v(101, 0);
// N�� 100 �̸� ���� 888,855,064,897�� ���´�.
// int�� ������ ����Ƿ� long long int�� �����

void Calc()
{
	v[1] = 1; v[2] = 1; v[3] = 1;
	v[4] = 2; v[5] = 2;

	for (int i = 6; i <= 100; i++)
	{
		v[i] = v[i - 1] + v[i - 5];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Calc();
	
	int T; cin >> T;

	for (int x = 0; x < T; x++)
	{
		int N; cin >> N;

		cout << v[N] << '\n';
	}
	return 0;
}