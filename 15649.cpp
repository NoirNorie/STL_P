#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 15649(N과 M)

int n; // 자연수의 개수
int m; // 수열의 길이

vector<bool> used(10, false);
vector<int> v(10);

void BT(int k) // 백트래킹 함수
{
	if (k == m) // 수열을 다 채운 경우
	{
		for (int i = 0; i < m; i++)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (used[i] == false) // 해당 숫자가 사용되지 않은 숫자라면
		{
			v[k] = i;
			used[i] = true; // 사용되었음을 표시한다
			BT(k + 1);
			used[i] = false; // 사용 해제
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	BT(0);

	return 0;
}