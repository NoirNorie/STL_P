#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

// 문제번호: 1966(프린터 큐)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	int N, M; // 문서의 개수, 지정한 문서의 위치
	int p; // 중요도에 사용할 변수
	queue<int> imp; // 중요도를 기록할 큐
	vector<int> v;
	int vi = 0; // 벡터의 인덱스
	int idx;
	int trial;

	cin >> tc;

	for (int i = 0; i < tc; i++) // 테스트 케이스 수 만큼 반복한다.
	{
		cin >> N >> M;
		idx = M;
		trial = 0; vi = 0;

		for (int j = 0; j < N; j++) // 문서의 개수만큼 반복한다.
		{
			cin >> p;	
			imp.push(p); // 입력한 숫자를 저장한다.
			v.push_back(p); // 순서 벡터에도 집어넣는다.
		}

		// 내림차순으로 중요도를 벡터에 정렬한다.
		sort(v.begin(), v.end(), greater<int>());

		while (imp.empty() != 1) // 큐가 빌 때까지 반복한다.
		{
			if (v[vi] == imp.front())
			{
				imp.pop(); // 우선순위 벡터와 같은 경우 큐에서 제거한다.
				vi++;
				trial++; // 제거 횟수 증가
				if (idx == 0) break;
			}
			else
			{
				// 아닐 경우 맨 앞 값을 뒤로 옮기고 제거한다.
				imp.push(imp.front());
				imp.pop();
			}
			if (--idx < 0) idx = imp.size() - 1;
		}
		cout << trial << '\n';

		while (!imp.empty())
		{
			imp.pop();
		}
		v.clear();
	}
	return 0;
}