// 16953 : A -> B

#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

deque<pair<int, int>> dq; // BFS를 수행할 뎈

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long A, B; cin >> A >> B;
	bool answer = false;
	dq.push_back({A, 1}); // 시작 숫자를 집어넣는다.
	while (dq.empty() != true)
	{
		long long current = dq.front().first; // 현재 숫자
		int trial = dq.front().second;  // 현재 카운트
		dq.pop_front();					// 맨 앞의 숫자를 빼낸다.

		if (current == B) // BFS로 수행했으므로 가장 빨리 나온 값이 최단 횟수
		{
			answer = true;
			cout << trial << '\n';
			break; // 더 수행할 필요가 없음
		}

		long long next1 = current * 2, next2 = current * 10 + 1;
		if (next1 <= B) dq.push_back({ next1, trial + 1 });
		if (next2 <= B) dq.push_back({ next2, trial + 1 });
	}
	if (answer == false) cout << -1 << '\n'; // 값이 나오지 않았다면 -1 반환
}
