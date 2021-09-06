#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ���� ��ȣ: 1018(ü���� �ٽ� ĥ�ϱ�)

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

	for (int i = 0; i < M; i++) // ���带 �Է� �޴´�.
	{
		cin >> st;
		str.push_back(st);
	}

	//if (M == 8 && N == 8) // ü�� �� ũ��� ������ ��� �߶󳻴� ��찡 �����Ƿ� ���� ó���Ѵ�
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
	// ü�� �� ũ�⺸�� �� Ŭ ��� �߶󳻴� ��쵵 �����ؾ� �Ѵ�.
	
	int min = 9999;

	for (int a = 0; a <= M - 8; a++)
	{	
		for (int b = 0; b <= N - 8; b++) // ���� �ݺ�
		{
			dif1 = 0; dif2 = 0;

			for (int i = 0; i < 8; i++) // ���� �ݺ�
			{
				for (int k = 0; k < 8; k++) // ���ڿ� Ž��
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