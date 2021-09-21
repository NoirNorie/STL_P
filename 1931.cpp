#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 1931(회의실 배정)

bool cmp(pair<int, int> v1, pair<int, int> v2) // 커스텀 비교 함수
{
	if (v1.second < v2.second) // 종료 시간이 짧은 것이 먼저 오도록 한다.
		return true;
	else if (v1.second == v2.second) // 종료 시간이 같다면
	{
		if (v1.first <= v2.first)
			return true;
		else
			return false;
	}
	else return false;
}

int main()
{
	int N; cin >> N;
	int cnt = 1;
	int end;
	
	vector<pair<int, int>> v(N + 1, make_pair(0, 0));

	for (int i = 1; i <= N; i++) // 시작 시간과 끝 시간을 입력받는다.
	{
		cin >> v[i].first >> v[i].second;
		
	}

	sort(v.begin(), v.end(), cmp); // 빨리 끝나는 순으로 정렬한다.

	end = v[1].second; // 가장 빨리 끝나는 것을 기록한다.
	for (int i = 2; i <= N; i++)
	{
		if (v[i].first >= end) // 종료 시간이 겹치지 않으면
		{
			end = v[i].second;
			cnt++;
		}
	}
	cout << cnt << '\n';


	return 0;
}