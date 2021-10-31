#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 1920(수 찾기)

vector<int> target_v;
// 전역변수 선언이 싫지만 시간 초과를 해결하기 위해서 여기다 선언함
// 벡터를 함수 호출마다 이동시키는 것도 시간을 잡아먹을 것임

void Binary_srch(int num)
{
	int left = 0, right = target_v.size() - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (target_v[mid] == num)
		{
			cout << 1 << '\n';
			return;
		}
		else if (target_v[mid] > num) right = mid - 1;
		else left = mid + 1;
	}

	// 찾지 못하였다면
	cout << 0 <<'\n';
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		target_v.push_back(num);
	}

	sort(target_v.begin(), target_v.end());

	int M; cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num; cin >> num;
		Binary_srch(num);
	}

	return 0;
}