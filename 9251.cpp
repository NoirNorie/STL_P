#include <iostream>
#include <string>
using namespace std;

// 문제 번호: 9251(LCS: Longest Common Subsequence)

int LCS[1001][1001] = { 0 };
// 최대 1000 길이의 문자열 2개이므로 1000 * 1000 배열을 만든다
// 맨 앞에 0 이 있어야 연산이 편해지므로 1001로 만든다

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
			if (x[i-1] == y[j-1]) // 같은 문자를 만났다면
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

// 행렬 출력
//for (int i = 0; i <= xlen; i++)
//{
//	for (int j = 0; j <= ylen; j++)
//	{
//		cout << LCS[i][j] << " ";
//	}
//	cout << '\n';
//}