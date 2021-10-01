#include <iostream>
using namespace std;

// ���� ��ȣ: 2630(������ �����)
// ���� ���� �� ���� Ʈ�� ����

int paper[128][128] = { 0, };
int blue = 0;
int white = 0;

void cut(int size, int a, int b)
{
	if (size == 1) // ũ�Ⱑ �� �ɰ� �� ���� ũ��� �پ����ٸ�
	{
		if (paper[a][b] == 1) blue++;
		else white++;
	}
	else // ũ�Ⱑ 2 �̻��̶��
	{
		int init = paper[a][b];
		bool chk = true;

		int row = size + b;
		int col = size + a;

		for (int i = a; i < col; i++)
		{
			for (int j = b; j < row; j++)
			{
				if (init != paper[i][j])
				{
					cut(size / 2, a, b);
					cut(size / 2, a + size / 2, b);
					cut(size / 2, a, b + size / 2);
					cut(size / 2, a + size / 2, b + size / 2);
					chk = false; break;
				}
			}
			if (chk == false) break;
		}
		if (chk == true)
		{
			if (init == 1) blue++;
			else white++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cout.tie(NULL);

	int N; cin >> N; // ������ �� ���� ũ�� �Է�
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> paper[i][j]; // ������ ���� �Է�
		}
	}

	cut(N, 0, 0);

	cout << white << '\n';
	cout << blue << '\n';

	return 0;
}