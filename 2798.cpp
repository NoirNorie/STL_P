#include <iostream>
#include <vector>
using namespace std;

int Close(int N, int M, vector<int> Cards);

int main()
{
	int N; // ī���� ����
	int M; // ���� ����
	int tmp; // ��� ����� ����

	cin >> N >> M; // ī���� ������ ���� ���ڸ� �Է¹޴´�.

	vector<int> Cards; // ���ڸ� ������ ���� ����

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		Cards.push_back(tmp); // ������
	}

	cout << Close(N, M, Cards) << endl;

	return 0;

}

int Close(int N, int M, vector<int> Cards)
{
	int MAX = 0; // ���� ����� ���ڸ� ���� ����
	int tmp;
	for (int i = 0; i < N-2; i++)
	{
		for (int j = i+1; j < N-1; j++)
		{
			for (int k = j+1; k < N; k++)
			{
				tmp = Cards[i] + Cards[j] + Cards[k];
				if (MAX < tmp)
				{
					if (tmp <= M)
					{
						MAX = tmp;
					}
	
				}
			}
		}
	}
	return MAX;
}