#include <iostream>
#include <string>
using namespace std;

// 문제 번호: 1992 (쿼드 트리)
// 색종이 문제는 재귀 순서에 영향을 받지 않지만 이번 문제는 재귀의 순서에 영향을 받는다

int tree[64][64] = { 0, };
string result = "";

void Quad(int n, int a, int b)
{
	if (n == 1) // 크기가 1 이하인 경우
	{
		if (tree[a][b] == '0') result += "0";
		else result += "1";
	}
	else // 크기가 2 이상이라면
	{
		int init = tree[a][b];
		bool chk = true;

		int row = n + b;
		int col = n + a;

		for (int i = a; i < col; i++)
		{
			for (int j = b; j < row; j++)
			{
				if (init != tree[i][j])
				{
					result += "(";
					Quad(n / 2, a, b);
					Quad(n / 2, a, b + n / 2);
					Quad(n / 2, a + n / 2, b);	
					Quad(n / 2, a + n / 2, b + n / 2);
					result += ")";
					chk = false; break;
				}
			}
			if (chk == false) break;
		}
		if (chk == true)
		{
			if (init == '0') result += "0";
			else result += "1";
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	string string_in;

	for (int i = 0; i < N; i++)
	{
		cin >> string_in;
		for (int j = 0; j < string_in.length(); j++)
		{
			tree[i][j] = string_in[j];
		}
	}

	Quad(N, 0, 0);

	cout << result << '\n';


	return 0;
}