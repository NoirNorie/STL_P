#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 1780(종이의 개수)
// 쿼드 트리 문제의 확장판으로 4분할이 아닌 9분할 문제
// 왠지 모르겠지만 이중 벡터를 사용하면 시간 초과가, 이중 배열을 사용하면 통과된다.
// 이중 배열 중에서도 배열의 크기가 적당히 크면 시간 초과가 나온다. 크게 해주자

int paper[3000][3000] = { 2, };


int alp = 0;
int bet = 0;
int gam = 0;

void Cut(int x, int y, int size)
{
	if (size == 1) // 크기가 1이라면
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
				if (init != paper[i][j]) // 살펴보는 중에 다른 것이 나왔다면
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