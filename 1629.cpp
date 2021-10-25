#include <iostream>
using namespace std;

// ���� ��ȣ: 1629(����)

long long int Div(long long int A, long long int B, long long int C)
{
	if (B == 1) // ������ �Ϸ�Ǿ��ٸ�
	{
		return A % C;
	}
	else // �߰� ������ �ʿ��ϴٸ�
	{
		long long int result = Div(A, B / 2, C);
		if (B % 2 != 0) // �������� �ɰ����� �ʴ´ٸ�
		{
			return result % C * result % C * (A % C) % C; // �����÷θ� �����ϱ� ���ؼ� %C�� �� ����� �Ѵ�.
		}
		else // �������� �ɰ����ٸ�
		{
			return result % C * result % C;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long int A, B, C;
	cin >> A >> B >> C;

	cout << Div(A,B,C) << '\n';

	return 0;
}