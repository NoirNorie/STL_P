#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 1780(������ ����)
// ���� Ʈ�� ������ Ȯ�������� 4������ �ƴ� 9���� ����
// ���� �𸣰����� ���� ���͸� ����ϸ� �ð� �ʰ���, ���� �迭�� ����ϸ� ����ȴ�.
// ���� �迭 �߿����� �迭�� ũ�Ⱑ ������ ũ�� �ð� �ʰ��� ���´�. ũ�� ������

int paper[3000][3000] = { 2, };


int alp = 0;
int bet = 0;
int gam = 0;

void Cut(int x, int y, int size)
{
	if (size == 1) // ũ�Ⱑ 1�̶��
	{
		if (paper[x][y] == -1) alp++;
		else if (paper[x][y] == 0) bet++;
		else gam++;
	}
	else
	{
		bool chk = true;
		int init = paper[x][y];
		int row = x + size;
		int col = y + size;

		for (int i = x; i < row; i++)
		{
			for (int j = y; j < col; j++)
			{
				if (init != paper[i][j]) // ���캸�� �߿� �ٸ� ���� ���Դٸ�
				{
					int lev1 = size / 3;
					int lev2 = (size * 2) / 3;

					Cut(x, y, lev1); Cut(x + lev1, y, lev1); Cut(x + lev2, y, lev1);
					Cut(x, y + lev1, lev1); Cut(x + lev1, y + lev1, lev1); Cut(x +  lev2, y + lev1, lev1);
					Cut(x, y + lev2, lev1); Cut(x + lev1, y + lev2, lev1); Cut(x + lev2, y + lev2, lev1);
					chk = false; break;
				}
			}
			if (chk == false) break;
		}
		if (chk == true)
		{
			if (init == -1) alp++;
			else if (init == 0) bet++;
			else gam++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> paper[i][j];
		}
	}

	Cut(0, 0, N);

	cout << alp << '\n';
	cout << bet << '\n';
	cout << gam << '\n';

	return 0;
}