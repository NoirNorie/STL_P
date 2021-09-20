#include <iostream>
#include <string>
using namespace std;

// ���� ��ȣ: 9251(LCS: Longest Common Subsequence)

int LCS[1001][1001] = { 0 };
// �ִ� 1000 ������ ���ڿ� 2���̹Ƿ� 1000 * 1000 �迭�� �����
// �� �տ� 0 �� �־�� ������ �������Ƿ� 1001�� �����

inline int MAX(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string x, y;
	cin >> x >> y;

	int xlen = x.length();
	int ylen = y.length();


	for (int i = 1; i <= xlen; i++)
	{
		for (int j = 1; j <= ylen; j++)
		{
			if (x[i-1] == y[j-1]) // ���� ���ڸ� �����ٸ�
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else
			{
				LCS[i][j] = MAX(LCS[i][j - 1], LCS[i - 1][j]);
			}
		}
	}


	cout << LCS[xlen][ylen] << '\n';

	return 0;
}

// ��� ���
//for (int i = 0; i <= xlen; i++)
//{
//	for (int j = 0; j <= ylen; j++)
//	{
//		cout << LCS[i][j] << " ";
//	}
//	cout << '\n';
//}