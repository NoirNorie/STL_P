#include <iostream>
using namespace std;

// ���� ��ȣ: 10250(ACM ȣ��)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; // �׽�Ʈ ���̽� ��
	int H, W, N; // ȣ���� �� ��, �� ���� ���� ��, �մ��� ��ȣ


	cin >> T;
	for (int i = 0; i < T; i++) // �׽�Ʈ ���̽� �� ��ŭ �ݺ��Ѵ�.
	{
		cin >> H >> W >> N; // �ش� �׽�Ʈ ���̽��� �Է��� �޴´�.

		int r = 0, c = 0; // ��ġ�� ��Ƴ� ����

		for (int j = 0; j < N; j += H) // ȣ ���� ã�Ƴ���.
			c++;

		r = (N - (c - 1) * H);

		cout << r * 100 + c << '\n';
	}

	return 0;
}