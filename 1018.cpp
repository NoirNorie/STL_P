#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 문제 번호: 1018(체스판 다시 칠하기)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string type1 = "WBWBWBWB";
	string type2 = "BWBWBWBW";
	
	int M, N, dif1 = 0, dif2 = 0;
	cin >> M >> N;

	vector<string> str;
	string st;

	for (int i = 0; i < M; i++) // 보드를 입력 받는다.
	{
		cin >> st;
		str.push_back(st);
	}

	//if (M == 8 && N == 8) // 체스 판 크기와 동일할 경우 잘라내는 경우가 없으므로 빨리 처리한다
	//{
	//	for (int i = 0; i < str.size(); i++)
	//	{
	//		for (int j = 0; j < str.size(); j++)
	//		{
	//			if (i % 2 == 0)
	//			{
	//				if (str[i][j] != type1[j]) dif1++;
	//				if (str[i][j] != type2[j]) dif2++;
	//			}
	//			else
	//			{
	//				if (str[i][j] != type2[j]) dif1++;
	//				if (str[i][j] != type1[j]) dif2++;
	//			}	
	//		}
	//	}
	//	cout << (dif1 <= dif2) ? dif1 : dif2 << '\n';
	//}
	// 체스 판 크기보다 더 클 경우 잘라내는 경우도 생각해야 한다.
	
	int min = 9999;

	for (int a = 0; a <= M - 8; a++)
	{	
		for (int b = 0; b <= N - 8; b++) // 가로 반복
		{
			dif1 = 0; dif2 = 0;

			for (int i = 0; i < 8; i++) // 세로 반복
			{
				for (int k = 0; k < 8; k++) // 문자열 탐색
				{
					if (i % 2 == 0)
					{
						if (str[a + i][b + k] != type1[k]) dif1++;
						if (str[a + i][b + k] != type2[k]) dif2++;
					}
					else
					{
						if (str[a + i][b + k] != type2[k]) dif1++;
						if (str[a + i][b + k] != type1[k]) dif2++;
					}
				}
			}
			int tmp = (dif1 <= dif2) ? dif1 : dif2;

			if (tmp < min) min = tmp;
		}
	}
	cout << min << '\n';
	

	return 0;
}