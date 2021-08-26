#include <iostream>
#include <vector>
using namespace std;

int Close(int N, int M, vector<int> Cards);

int main()
{
	int N; // 카드의 개수
	int M; // 지정 숫자
	int tmp; // 잠시 사용할 변수

	cin >> N >> M; // 카드의 개수와 지정 숫자를 입력받는다.

	vector<int> Cards; // 숫자를 저장할 벡터 생성

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		Cards.push_back(tmp); // 저장함
	}

	cout << Close(N, M, Cards) << endl;

	return 0;

}

int Close(int N, int M, vector<int> Cards)
{
	int MAX = 0; // 가장 가까운 숫자를 담을 변수
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