#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 15650(N과 M 2)

int N; // 자연수의 개수
int M; // 수열의 길이

vector<bool> used(10, false);
vector<int> v(10);

void BT(int k)
{
	if (k == M) // 수열의 길이와 동일해지면
	{
		for (int i = 0; i < M; i++)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = 1; i <= N; i++)
	{
		if (used[i] == false) // 사용된 적 없다면
		{
			used[i] = true; // 사용했다고 표시한다.
			v[k] = i;
			if (k > 0) // 범위 이탈 방지
			{
				if (v[k - 1] < v[k]) // 
				{
					BT(k + 1);
				}
			}
			else // 일단 한번은 돌려본다.
			{
				BT(k + 1);
			}
			used[i] = false; // 사용 완료 표시
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	BT(0);
	return 0;
}