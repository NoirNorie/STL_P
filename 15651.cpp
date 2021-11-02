#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 15652(N과 M 3)
// 중복 허용 백트래킹

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
		// 중복 허용 백트래킹
		if (k > 0)
		{
			v[k] = i;
			if (v[k - 1] <= v[k]) // 이전 숫자보다 크거나 같아야 한다.
			{
				BT(k + 1);
			}
		}
		else // 최초 1회
		{
			v[k] = i;
			BT(k + 1);
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
